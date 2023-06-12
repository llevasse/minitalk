/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/12 15:42:38 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

struct s_boolean_extra	g_extra;

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2 && g_extra.file_ended)
		ft_exit("Str printed :)", 0);
	else if (sig == SIGUSR2)
		ft_printf("Line #%d printed\n", g_extra.line_index);
	(void)context;
	(void)siginfo;
}

void	print_next_args(int argc, char **argv, int pid)
{
	g_extra.file_ended = 0;
	if (g_extra.from_txt && (g_extra.t_flag_position < g_extra.print_next_args
			|| !g_extra.print_c_by_c))
		send_file(pid, open(argv[g_extra.t_flag_position], O_RDONLY), &g_extra);
	g_extra.line_index = 0;
	if (g_extra.print_next_args)
	{
		while ((g_extra.print_next_args + g_extra.line_index) < argc)
		{
			send_str(pid, argv[(g_extra.print_next_args
					+ g_extra.line_index++)], g_extra);
			send_char(pid, '\n', g_extra);
		}
		send_char(pid, '\n', g_extra);
	}
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;

	if (argc <= 2)
		invalid_argument(argv[1]);
	g_extra.log_fd = -1;
	check_n_get_flags_client(&g_extra, argc, argv);
	if (g_extra.help == 1)
		print_help_client();
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (g_extra.print_next_args || g_extra.from_txt)
		print_next_args(argc, argv, pid);
	else
		send_str(pid, argv[argc - 1], g_extra);
	g_extra.file_ended = 1;
	send_char(pid, '\0', g_extra);
	while (1)
		;
	return (0);
}
