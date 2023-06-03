/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:30 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/03 21:53:44 by llevasse         ###   ########.fr       */
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
	extra->from_txt = 0;
	extra->logged = 0;
	extra->binnary_logged = 0;
	if (check_str_in_array(argc, argv, "-t", argc))
	{
		extra->from_txt = 1;
		extra->t_flag_position = check_str_in_array(argc, argv, "-t", argc);
		if (!ft_strnstr(argv[extra->t_flag_position], ".txt",
				ft_strlen(argv[extra->t_flag_position])))
			invalid_argument(0);
	}
	if (check_str_in_array(argc, argv, "-l", argc))
	{
		extra->log_fd = open("client_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
	}
	else if (check_str_in_array(argc, argv, "-lb", argc))
	{
		extra->log_fd = open("client_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
		extra->binnary_logged = 1;
	}
}

// t_rgb	init_rgb(t_boolean_extra extra)
// {
// 	t_rgb	rgb;

// 	if (!extra.is_rbw)
// 		return ;
// }

void	check_n_get_flags_server(t_boolean_extra *extra, int argc, char **argv)
{
	if (check_str_in_array(argc, argv, "-c", argc))
		extra->print_c_by_c = 1;
	else
		extra->print_c_by_c = 0;
	if (check_str_in_array(argc, argv, "-l", argc))
	{
		extra->log_fd = open("server_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
	}
	else if (check_str_in_array(argc, argv, "-lb", argc))
	{
		extra->log_fd = open("server_log.log", O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
		extra->binnary_logged = 1;
		write(extra->log_fd, "{", 1);
	}
	extra->is_rbw = 0;
	if (check_str_in_array(argc, argv, "-rbw", argc))
	{
		extra->is_rbw = 1;
		extra->rgb.r = 255;
		extra->rgb.r_top = 1;
		extra->rgb.g = 0;
		extra->rgb.g_top = 0;
		extra->rgb.b = 0;
		extra->rgb.b_top = 0;
	}
}

void	ft_exit(char *str, int status)
{
	ft_printf("%s\n", str);
	exit(status);
}
