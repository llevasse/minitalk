/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:26:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/30 15:22:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	send_file(int pid, int fd, t_boolean_extra extra)
{
	char	*str;

	str = get_next_line(fd);
	send_str(pid, str, extra);
	while (str)
	{
		free(str);
		str = NULL;
		str = get_next_line(fd);
		if (!str)
			break ;
		send_str(pid, str);
	}
	close(fd);
}

void	send_str(int pid, char *str, t_boolean_extra extra)
{
	while (*str)
	{
		if (!send_char(pid, *(str++), extra))
		{
			free(str);
			exit(0);
		}
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
	return (1);
}
