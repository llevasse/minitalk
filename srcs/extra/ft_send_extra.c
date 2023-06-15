/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:26:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/15 22:38:57 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

/// @brief Send str to server.
/// @param pid Process id of server,
/// @param fd file descriptor of file,
/// @param extra pointer to extra structure containing clients options.
void	send_file(int pid, int fd, t_extra *extra)
{
	unsigned char	*str;

	str = get_next_line(fd);
	if (!str)
		return ((void)(close(fd), ft_exit("Unable to open file", 1)));
	while (str)
	{
		send_str(pid, (char *)str, *extra);
		free(str);
		extra->line_index++;
		str = get_next_line(fd);
	}
	send_char(pid, '\n', *extra);
	close(fd);
}

/// @brief Send str to server.
/// @param pid Process id of server,
/// @param str str to send,
/// @param extra extra structure containing clients options.
void	send_str(int pid, char *str, t_extra extra)
{
	if (!extra.from_txt && extra.binnary_logged)
		write(extra.log_fd, "{", 1);
	while (*str)
	{
		if (!send_char(pid, *str, extra))
			exit((int)(free(str), 0));
		str++;
	}
	if (!extra.from_txt && !extra.print_next_args)
		send_char(pid, '\n', extra);
	send_char(pid, '\0', extra);
}

/// @brief Send char to server.
/// @param pid Process id of server,
/// @param c character to send,
/// @param extra extra structure containing clients options.
/// @return Return 1 if char was correctly sent or 0 if not.
int	send_char(int pid, char c, t_extra extra)
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
