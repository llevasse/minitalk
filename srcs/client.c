/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/11 19:31:40 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;

	if (argc != 3 && argc != 4)
	{
		ft_printf("Error. Invalid argument\n");
		ft_printf("sould be : ./client {pid} \"{string}\"\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 4)
		if (!use_file(pid, argv))
			return (1);
	if (argc == 3)
		send_str(pid, argv[2]);
	send_char(pid, '\n');
	send_char(pid, '\0');
	while (1)
		;
	return (1);
}

int	use_file(int pid, char **argv)
{
	if (ft_strcmp(argv[2], "-t") || !ft_strnstr(argv[3], ".txt",
			ft_strlen(argv[3])))
	{
		ft_printf("Error. Invalid argument\n");
		ft_printf("sould be : ./client {pid} -t {file.txt} \n");
		return (0);
	}
	send_file(pid, open(argv[3], O_RDONLY));
	return (1);
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2)
		ft_exit("Str printed", 0);
	(void)context;
	(void)siginfo;
}

void	ft_exit(char *str, int status)
{
	ft_printf("%s\n", str);
	exit(status);
}
