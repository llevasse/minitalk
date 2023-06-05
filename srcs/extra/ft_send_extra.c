/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:26:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/05 11:58:38 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	send_file(int pid, int fd, t_boolean_extra extra)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return ((void)(close(fd), ft_exit("Unable to open file", 1)));
	if (extra.binnary_logged == 1)
		write(extra.log_fd, "{", 1);
	send_str(pid, str, extra);
	while (str)
	{
		free(str);
		str = NULL;
		str = get_next_line(fd);
		if (!str)
			break ;
		send_str(pid, str, extra);
	}
	send_char(pid, '\n', extra);
	if (extra.binnary_logged == 1)
		write(extra.log_fd, ",", 1);
	if (extra.logged == 1)
		write(extra.log_fd, "\n", 1);
	if (extra.binnary_logged == 1)
		write(extra.log_fd, "}-{", 3);
	send_char(pid, '\0', extra);
	if (extra.binnary_logged == 1)
		write(extra.log_fd, "}", 1);
	close(fd);
}

void	send_str(int pid, char *str, t_boolean_extra extra)
{
	while (*str)
	{
		if (!send_char(pid, *str, extra))
			exit((int)(free(str), 0));
		if (extra.binnary_logged == 1)
			write(extra.log_fd, ",", 1);
		if (extra.logged == 1)
			write(extra.log_fd, &(*str), 1);
		if (extra.binnary_logged == 1)
			write(extra.log_fd, "}-{", 3);
		str++;
	}
	if (!extra.from_txt)
	{
		send_char(pid, '\n', extra);
		if (extra.binnary_logged == 1)
			write(extra.log_fd, ",", 1);
		if (extra.logged == 1)
			write(extra.log_fd, "\n", 1);
		if (extra.binnary_logged == 1)
			write(extra.log_fd, "}-{", 3);
		send_char(pid, '\0', extra);
		if (extra.binnary_logged == 1)
			write(extra.log_fd, "}", 1);
	}
}

int	send_char(int pid, char c, t_boolean_extra extra)
{
	int	size_char;

	size_char = -1;
	while (size_char++ < 7)
	{
		if (!!((c << size_char) & 0x80))
		{
			if (log_char(pid, extra, SIGUSR2) == -1)
				return (0);
		}
		else
		{
			if (log_char(pid, extra, SIGUSR1) == -1)
				return (0);
		}
		usleep(1000);
	}
	return (1);
}

int	log_char(int pid, t_boolean_extra extra, int sig)
{
	if (sig == SIGUSR1)
	{
		if (extra.binnary_logged)
			write(extra.log_fd, "0", 1);
		return (kill(pid, SIGUSR1));
	}
	if (sig == SIGUSR2)
	{
		if (extra.binnary_logged)
			write(extra.log_fd, "1", 1);
		return (kill(pid, SIGUSR2));
	}
	return (1);
}
