/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:26:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/07 12:58:07 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	send_file(int pid, int fd, t_extra extra)
{
	unsigned char	*str;

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
	send_char(pid, (unsigned char)'\n', extra);
	send_char(pid, (unsigned char)'\0', extra);
	close(fd);
}

void	send_str(int pid, unsigned char *str, t_extra extra)
{
	if (!extra.from_txt && extra.binnary_logged)
		write(extra.log_fd, "{", 1);
	while (*str)
	{
		if (!send_char(pid, *str, extra))
			exit((int)(free(str), 0));
		str++;
	}
	if (!extra.from_txt)
	{
		send_char(pid, (unsigned char)'\n', extra);
		send_char(pid, (unsigned char)'\0', extra);
	}	
}

int	send_char(int pid, unsigned char c, t_extra extra)
{
	int	size_char;

	size_char = -1;
	while (size_char++ < 7)
	{
		if (!!((c << size_char) & 0x80))
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		usleep(1000);
	}
	print_log(extra, c);
	return (1);
}
