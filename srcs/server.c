/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/22 09:59:49 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int		test = 0;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		ft_printf("(sender pid : %i)", siginfo->si_pid);
		if (sig == SIGUSR1)
			write(1, "0", 1);
		if (sig == SIGUSR2)
			write(1, "1", 1);
	}
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
