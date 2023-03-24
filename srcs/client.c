/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/24 11:33:02 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Error. Invalid argument\n");
		ft_printf("sould be : ./client {pid} \"{string}\"\n");
		return (1);
	}
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
		write(1, "", 1);
	if (sig == SIGUSR2)
		ft_printf("Str printed\n");
	(void)context;
	(void)siginfo;
}

void	send_str(int pid, char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\n');
	send_char(pid, '\0');
}

void	send_char(int pid, char c)
{
	int					size_char;
	struct sigaction	sa;

	size_char = -1;
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
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
		usleep(1000);
	}
}
