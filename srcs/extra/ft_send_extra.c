/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:26:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/07 23:58:00 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	send_file(int pid, int fd, t_extra extra)
{
	unsigned char	str[1];
	int				count;

	//str = get_next_line(fd);
	count = read(fd, str, 1);
	if (count < 0 || str[0] == 0)
		return ((void)(close(fd),
						ft_exit("Unable to open file",
								1)));
	if (extra.binnary_logged == 1)
		write(extra.log_fd, "{", 1);
	if (!send_char(pid, str[0], extra))
		exit(0);
	while (count > 0)
	{
		count = read(fd, str, 1);
		if (str[0] == 0 || count <= 0)
			break ;
		if (!send_char(pid, str[0], extra))
			exit(0);
	}
	send_char(pid, (unsigned char)'\n', extra);
	send_char(pid, (unsigned char)'\0', extra);
	close(fd);
}

void	send_str_file(int pid, unsigned char str[1], t_extra extra)
{
	int	i;

	i = 0;
	if (!extra.from_txt && extra.binnary_logged)
		write(extra.log_fd, "{", 1);
	while (str[i])
	{
		if (!send_char(pid, str[i], extra))
			exit(0);
		i++;
	}
	if (!extra.from_txt)
	{
		send_char(pid, (unsigned char)'\n', extra);
		send_char(pid, (unsigned char)'\0', extra);
	}
}
void	send_str(int pid, unsigned char *str, t_extra extra)
{
	if (extra.binnary_logged)
		write(extra.log_fd, "{", 1);
	while (*str)
	{
		if (!send_char(pid, str[0], extra))
			exit(0);
		str++;
	}
	send_char(pid, (unsigned char)'\n', extra);
	send_char(pid, (unsigned char)'\0', extra);
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
