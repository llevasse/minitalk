 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/15 14:58:40 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_extra.h"

struct s_sig_char	g_sig_char;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	if (g_sig_char.need_set_pid == 1)
	{
		g_sig_char.client_pid = siginfo->si_pid;
		g_sig_char.need_set_pid = 0;
	}
	if (siginfo->si_pid != g_sig_char.client_pid)
		return ((void)kill(siginfo->si_pid, SIGUSR2));
	if (sig == SIGUSR2)
		g_sig_char.c |= (1 << g_sig_char.shift);
	g_sig_char.shift--;
	print_sig_char(siginfo, &g_sig_char);
	if (kill(g_sig_char.client_pid, SIGUSR1) == -1)
		ft_exit("Error while sending signal :(", 1);
	(void)context;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	t_extra				extra;

	init_server(&extra, argc, argv, &g_sig_char);
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0)
		ft_exit("Error in sending signal", 1);
	while (1)
		;
	return (0);
}
