/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/22 15:05:34 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3)
		return (ft_printf("Error. Invalid argument\nsould be : ./client {pid} {string}\n"));
	ft_printf("client pid : %i\n", getpid());
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
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

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR1)
		write(1, "0", 1);
	if (sig == SIGUSR2)
		write(1, "1", 1);
	(void)context;
	(void)siginfo;
}

void	send_str(int pid, char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\n');
}

void	send_char(int pid, char c)
{
	struct sigaction sa;
	int size_char;

	size_char = -1;
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_printf("sigaction");
		return ;
	}
	while (size_char++ < 7)
	{
		if (!!((c << size_char) & 0x80))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
	}
	ft_printf("\n");
	size_char = -1;
	while (size_char++ < 7)
	{
		ft_printf("%i", !!((c << size_char) & 0x80));
	}
	ft_printf("\n");
}