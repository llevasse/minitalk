/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/10 21:15:42 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2)
		ft_exit("Str printed", 0);
	(void)context;
	(void)siginfo;
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;
	t_boolean_extra		extra;

	if (argc <= 2)
		invalid_argument(0);
	extra.log_fd = -1;
	check_n_get_flags_client(&extra, argc, argv);
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	extra.str_position = argc;
	if (extra.from_txt)
		send_file(pid, open(argv[extra.t_flag_position], O_RDONLY), extra);
	else
		send_str(pid, argv[extra.str_position - 1], extra);
	while (1)
		;
	return (0);
}

