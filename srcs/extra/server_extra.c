/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/14 16:41:24 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_extra.h"

struct s_sig_char	*g_sig_char;

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	t_sig_char	*temp;

	temp = NULL;
	if (g_sig_char->client_pid != siginfo->si_pid
		&& g_sig_char->index_sig_char == 0)
		g_sig_char->client_pid = siginfo->si_pid;
	if (g_sig_char->client_pid != siginfo->si_pid)
		connect_temp(siginfo->si_pid, g_sig_char, temp);
	else
		temp = g_sig_char;
	if (sig == SIGUSR2)
		temp->c |= (1 << temp->shift);
	temp->shift--;
	print_sig_char(siginfo, temp);
	(void)context;
}

void	print_single_char(unsigned char c, t_sig_char *sig_char)
{
	if (sig_char->extra->is_rbw && c <= 127)
		print_color(&sig_char->extra->rgb);
	print_log(*(sig_char->extra), c);
	write(1, &sig_char->c, 1);
}

void	print_sig_char(siginfo_t *siginfo, t_sig_char *sig_char)
{
	if (sig_char->shift < 0)
	{
		if (sig_char->extra->print_c_by_c == 0)
		{
			if (!sig_char->mini_str)
				sig_char->mini_str = ft_lstnew(sig_char->c);
			else
				ft_lstadd_back(&sig_char->mini_str, ft_lstnew(sig_char->c));
		}
		else
			print_single_char(sig_char->c, sig_char);
		if (sig_char->c == '\0')
		{
			if (sig_char->nb_null_received++ >= 1)
			{
				if (sig_char->extra->print_c_by_c == 0)
					ft_lstprint_extra(sig_char->mini_str, sig_char->extra);
				if (kill(sig_char->client_pid, SIGUSR2) == -1)
					(void)(free(g_sig_char),
							ft_exit("Error in sending SIGUSR2 :(", 1));
				sig_char->mini_str = NULL;
				ft_del_one_sig_c(g_sig_char, sig_char->client_pid);
			}
		}
		if (sig_char)
		{
			sig_char->shift = 7;
			sig_char->c = 0;
		}
	}
	else if (kill(sig_char->client_pid, SIGUSR1) == -1)
		(void)(free(g_sig_char), ft_exit("Error while sending SIGUSR1 :(", 1));
	(void)siginfo;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	t_boolean_extra		extra;

	init_server(&extra, argc, argv);
	g_sig_char = ft_new_sig_c(getpid(), &extra, 0);
	g_sig_char->extra->pid = getpid();
	if (!g_sig_char)
		ft_exit("Error initialising malloc", 1);
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
