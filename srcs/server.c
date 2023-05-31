/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 10:58:21 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

struct s_sig_char	g_sig_char;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	g_sig_char.client_pid = siginfo->si_pid;
	if (sig == SIGUSR2)
		g_sig_char.c |= (1 << g_sig_char.shift);
	g_sig_char.shift--;
	if (g_sig_char.shift < 0)
	{
		write(1, &g_sig_char.c, 1);
		if (g_sig_char.c == '\0')
		{
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_exit("Error in sending signal", 0);
		}
		g_sig_char.shift = 7;
		g_sig_char.c = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (kill(g_sig_char.client_pid, SIGUSR1) == -1)
			ft_exit("Error in sending signal", 0);
	}
	(void)context;
}

void	ft_exit(char *str, int status)
{
	ft_printf("%s\n", str);
	exit(status);
}

int	main(void)
{
	struct sigaction	sa;
	__pid_t				pid;

	pid = getpid();
	g_sig_char.shift = 7;
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("pid : %i\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0)
		ft_exit("Error in sending signal", 0);
	while (1)
		;
}
