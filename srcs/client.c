/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/21 12:27:00 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3)
		return (ft_printf("Error. Invalid argument\nsould be : ./client {pid} {string}\n"));
	pid = ft_atoi(argv[1]);
	ft_printf("pid = %i\n", pid);
	kill(pid, SIGUSR1);
}

/* print char as binary

c = 'a'
size_char = 8
while (size_char-- > 0)
{
	ft_printf("%i", !!((c << 1) & 0x80))
	c <<= 1
}

*/


void	send_char(int pid, char c)
{
}