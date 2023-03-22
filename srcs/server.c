/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:38 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int				shift = -1;
	static unsigned char	c;
	if (shift < 0)
	{
		shift = 7;
		c = 0;
	}
	if (sig == SIGUSR2)
		c |= (1 << shift);
	shift--;
	if (shift < 0 && c)
	{
		write(1, &c, 1);
		c = 0;
	}
	if (sig == SIGUSR1)
		kill(siginfo->si_pid, SIGUSR1);
	else
		kill(siginfo->si_pid, SIGUSR2);
	(void)context;
}

int	main(void)
{
	int					char_size;
	struct sigaction	sa;
	__pid_t				pid;

	pid = getpid();
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("pid : %i\n", pid);
	char_size = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_printf("sigaction");
		return (1);
	}
	while (1)
	{
		pause();
	}
	(void)char_size;
}
