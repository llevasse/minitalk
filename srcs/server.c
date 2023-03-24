/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/23 18:26:06 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

struct s_sig_char sig_char;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	sig_char.client_pid = siginfo->si_pid;
	if (sig_char.shift < 0)
	{
		sig_char.shift = 7;
		sig_char.c = 0;
	}
	if (sig == SIGUSR2)
		sig_char.c |= (1 << sig_char.shift);
	sig_char.shift--;
	if (sig_char.shift < 0)
	{
		write(1, &sig_char.c, 1);
		if (sig_char.c == '\0')
			kill(siginfo->si_pid, SIGUSR2);
		sig_char.c = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
		kill(sig_char.client_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	int					char_size;
	struct sigaction	sa;
	__pid_t				pid;

	pid = getpid();
	sig_char.shift = -1;
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
		pause();
	(void)char_size;
}
