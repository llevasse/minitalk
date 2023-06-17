/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/17 20:31:31 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_is_test;

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error. Invalid argument\n");
		ft_printf("sould be : ./client {pid} \"{string}\"\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		ft_exit("Invalid pid", 1);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	test_serv(pid);
	if (argc == 3)
		send_str(pid, argv[2]);
	send_char(pid, '\n');
	send_char(pid, '\0');
	while (1)
		;
	return (1);
}

/// @brief Check the connection to the server.
/// @param pid Process id {PID} of the server.
void	test_serv(int pid)
{
	g_is_test = 1;
	if (!send_char(pid, '\0'))
		ft_exit("Unable to make connexion to server, check pid :(", 1);
	g_is_test = 0;
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2 && g_is_test == 0)
		ft_exit("Str printed", 0);
	if (sig == SIGUSR2 && g_is_test == 1)
		ft_exit("Unable to connect to server :(", 1);
	(void)context;
	(void)siginfo;
}

void	ft_exit(char *str, int status)
{
	ft_printf("%s\n", str);
	exit(status);
}
