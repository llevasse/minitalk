/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/11 19:40:21 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

int		g_ended_send;

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2 && g_ended_send)
		ft_exit("Str printed", 0);
	else if (sig == SIGUSR2)
		ft_exit("Error while sending", 0);
	(void)context;
	(void)siginfo;
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;
	t_boolean_extra		extra;

	if (argc <= 2)
		invalid_argument(argv[1]);
	extra.log_fd = -1;
	g_ended_send = 0;
	check_n_get_flags_client(&extra, argc, argv);
	if (extra.help == 1)
		print_help_client();
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (extra.from_txt)
		send_file(pid, open(argv[extra.t_flag_position], O_RDONLY), extra);
	else
		send_str(pid, argv[argc - 1], extra);
	g_ended_send = 1;
	while (1)
		;
	return (0);
}
