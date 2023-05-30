/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 01:15:46 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_extra.h"

struct s_sig_char	g_sig_char;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	g_sig_char.client_pid = siginfo->si_pid;
	if (sig == SIGUSR2)
	{
		g_sig_char.c |= (1 << g_sig_char.shift);
		if (g_sig_char.extra.binnary_logged)
			write(g_sig_char.extra.log_fd, "1", 1);
	}
	else
	{
		if (g_sig_char.extra.binnary_logged)
			write(g_sig_char.extra.log_fd, "0", 1);
	}
	g_sig_char.shift--;
	print_sig_char(siginfo);
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (kill(g_sig_char.client_pid, SIGUSR1) == -1)
			ft_exit("Error in sending signal", 0);
	}
	(void)context;
}

void	print_sig_char(siginfo_t *siginfo)
{
	if (g_sig_char.shift < 0)
	{
		if (g_sig_char.extra.binnary_logged)
			write(g_sig_char.extra.log_fd, ",", 1);
		if (g_sig_char.extra.logged)
			write(g_sig_char.extra.log_fd, &g_sig_char.c, 1);
		if (g_sig_char.extra.binnary_logged)
			write(g_sig_char.extra.log_fd, "}{", 2);
		write(1, &g_sig_char.c, 1);
		if (g_sig_char.c == '\0')
		{
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_exit("Error in sending signal", 0);
		}
		g_sig_char.shift = 7;
		g_sig_char.c = 0;
	}
}

void	ft_exit(char *str, int status)
{
	ft_printf("%s\n", str);
	exit(status);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	__pid_t				pid;
	t_boolean_extra		extra;

	pid = getpid();
	ft_printf("pid : %i\n", pid);
	check_n_get_flags_server(&extra, argc, argv);
	g_sig_char.shift = 7;
	g_sig_char.extra = extra;
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0)
		ft_exit("Error in sending signal", 0);
	while (1)
		;
}
