/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/16 14:18:24 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

struct s_extra	g_extra;

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2 && g_extra.file_ended && g_extra.line_index >= 0)
		ft_exit("Str printed :)", 0);
	else if (sig == SIGUSR2 && g_extra.line_index >= 0)
		ft_printf("Line #%d printed\n", g_extra.line_index);
	if (sig == SIGUSR2 && g_extra.line_index == -1)
	{
		sleep(3);
		ft_exit("Unable to make connection. \nTry again in a few seconds.", 1);
	}
	(void)context;
	(void)siginfo;
}

/// @brief Check the connection to the server.
/// @param pid Process id {PID} of the server.
void	test_serv(int pid)
{
	g_extra.line_index = -1;
	if (!send_char(pid, '\0', g_extra))
		ft_exit("Unable to make connexion to server, check pid :(", 1);
	g_extra.line_index = 0;
}

/// @brief Send text file content and/or rest of arguments to the server.
/// @param argc Nb of element in argv,
/// @param argv Elements given to the client.
/// @param pid Process id {PID} of the server.
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
	send_char(pid, '\0', g_extra);
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;

	init_client(&g_extra, argc, argv, &pid);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	test_serv(pid);
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
