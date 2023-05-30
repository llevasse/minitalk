/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:30 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 01:20:25 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

int	invalid_argument(int status)
{
	ft_printf("Error. Invalid argument\n");
	ft_printf("Use ./client -h for help\n");
	exit(status);
}

/// @brief
/// @param argc numbers of items in array
/// @param ar array of string
/// @param str string to search in array
/// @param len_ar numbers of array items to check
/// @return
int	check_str_in_array(int argc, char **ar, const char *str, int len_ar)
{
	int	i;

	i = 0;
	if (len_ar > argc)
		len_ar = argc;
	while (i < len_ar)
	{
		if (!ft_strcmp(ar[i++], str))
			return (i);
	}
	return (0);
}

void	check_n_get_flags_client(t_boolean_extra *extra, int argc, char **argv)
{
	if (check_str_in_array(argc, argv, "-t", 7))
	{
		extra->from_txt = 1;
		extra->t_flag_position = check_str_in_array(argc, argv, "-t", 7);
		ft_printf("Use of flag -t in position %d\n", extra->t_flag_position);
		if (!ft_strnstr(argv[extra->t_flag_position], ".txt",
				ft_strlen(argv[extra->t_flag_position])))
			invalid_argument(0);
	}
	if (check_str_in_array(argc, argv, "-l", 7))
	{
		ft_printf("Use of -l\n");
		extra->log_fd = open("client_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
	}
	else if (check_str_in_array(argc, argv, "-lb", 7))
	{
		ft_printf("Use of -lb\n");
		extra->log_fd = open("client_log.log", O_RDWR | O_CREAT, 0666);
		ft_printf("fd : %d\n", extra->log_fd);
		extra->logged = 1;
		extra->binnary_logged = 1;
	}
}

void	check_n_get_flags_server(t_boolean_extra *extra, int argc, char **argv)
{
	if (check_str_in_array(argc, argv, "-l", 7))
	{
		extra->log_fd = open("server_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
	}
	else if (check_str_in_array(argc, argv, "-lb", 7))
	{
		extra->log_fd = open("server_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
		extra->binnary_logged = 1;
		write(extra->log_fd, "{", 1);
	}
}
