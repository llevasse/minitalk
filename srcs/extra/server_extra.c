/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/05 17:07:58 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_extra.h"

struct s_sig_char	g_sig_char;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	g_sig_char.client_pid = siginfo->si_pid;
	if (sig == SIGUSR2)
		g_sig_char.c |= (1 << g_sig_char.shift);
	g_sig_char.shift--;
	print_sig_char(siginfo);
	if (kill(g_sig_char.client_pid, SIGUSR1) == -1)
		ft_exit("Error in sending signal", 1);
	(void)context;
}

void	print_single_char(unsigned char c)
{
	ft_put_markdown(&g_sig_char.extra, c);
	if (g_sig_char.extra.md.bold_c_nb > 0)
		return ;
	if (g_sig_char.extra.is_rbw && c <= 127)
		print_color(&g_sig_char.extra.rgb);
	print_log(g_sig_char.extra, c);
	write(1, &g_sig_char.c, 1);
}

void	print_sig_char(siginfo_t *siginfo)
{
	if (g_sig_char.shift < 0)
	{
		if (g_sig_char.extra.print_c_by_c == 0)
		{
			if (!g_sig_char.mini_str)
				g_sig_char.mini_str = ft_lstnew(g_sig_char.c);
			else
				ft_lstadd_back(&g_sig_char.mini_str, ft_lstnew(g_sig_char.c));
		}
		else
			print_single_char(g_sig_char.c);
		if (g_sig_char.c == '\0')
		{
			if (g_sig_char.extra.print_c_by_c == 0)
				ft_lstprint(g_sig_char.mini_str, &g_sig_char.extra);
			g_sig_char.mini_str = NULL;
			if (kill(siginfo->si_pid, SIGUSR2) == -1)
				ft_exit("Error in sending signal", 1);
		}
		g_sig_char.shift = 7;
		g_sig_char.c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	__pid_t				pid;
	t_extra		extra;

	pid = getpid();
	ft_printf("pid : %i\n", pid);
	check_n_get_flags_server(&extra, argc, argv);
	if (extra.logged)
		extra.log_fd = open("server_log.log", O_RDWR | O_CREAT, 0666);
	g_sig_char.shift = 7;
	g_sig_char.mini_str = NULL;
	g_sig_char.extra = extra;
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0)
		ft_exit("Error in sending signal", 1);
	while (1)
		;
}
