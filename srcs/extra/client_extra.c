/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/30 22:25:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;
	t_boolean_extra		extra;

	extra.log_fd = -1;
	check_n_get_flags(&extra, argc, argv);
	pid = ft_atoi(argv[1]);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	extra.str_position = argc;
	if (extra.from_txt)
		send_file(pid, open(argv[3], O_RDONLY), extra);
	else
		send_str(pid, argv[extra.str_position - 1], extra);
	send_char(pid, '\n', extra);
	send_char(pid, '\0', extra);
	return (0);
}

void	check_n_get_flags(t_boolean_extra *extra, int argc, char **argv)
{
	if (argc <= 2)
		invalid_argument(0);
	if (check_str_in_array(argc, argv, "-t", 7))
	{
		extra->from_txt = 1;
		extra->t_flag_position = check_str_in_array(argc, argv, "-t", 7);
		ft_printf("Use of flag -t in position %d\n", extra->t_flag_position);
		if (!ft_strnstr(argv[extra->t_flag_position], ".txt",
				ft_strlen(argv[extra->t_flag_position])))
			invalid_argument(0);
		//extra->str_position += 2;
	}
	if (check_str_in_array(argc, argv, "-l", 7))
	{
		ft_printf("Use of -l\n");
		extra->log_fd = open("client_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
		//extra->str_position++;
	}
	else if (check_str_in_array(argc, argv, "-lb", 7))
	{
		ft_printf("Use of -lb\n");
		extra->log_fd = open("client_log.log", O_RDWR | O_CREAT, 0666);
		ft_printf("fd : %d\n", extra->log_fd);
		extra->logged = 1;
		extra->binnary_logged = 1;
		//extra->str_position++;
	}
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR2)
		write(1, "Str printed\n", 12);
	(void)context;
	(void)siginfo;
}

/// @brief
/// @param argc numbers of items in array
/// @param ar array of string
/// @param str string to search in array
/// @param len_ar numbers of array items to check
/// @return
int	check_str_in_array(int argc, char **ar, const char *str, int len_ar)
{
	int i;

	i = 2;
	if (len_ar > argc)
		len_ar = argc;
	while (i < len_ar)
	{
		if (!ft_strcmp(ar[i++], str))
			return (i);
	}
	return (0);
}