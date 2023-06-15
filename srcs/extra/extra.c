/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:30 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/15 14:09:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

int	invalid_argument(char *str)
{
	if (!ft_strcmp(str, "-h"))
		print_help_client();
	ft_printf("Error. Invalid argument\n");
	ft_printf("Use ./client -h for help\n");
	exit(0);
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
	if (len_ar > argc || len_ar == 0)
		len_ar = argc;
	while (i < len_ar)
	{
		if (!ft_strcmp(ar[i++], str))
			return (i);
	}
	return (0);
}

void	check_flags_client(t_extra *extra, int argc, char **argv)
{
	init_extra(extra);
	if (check_str_in_array(argc, argv, "-h", 3))
		return ((void)(extra->help = 1));
	if (check_str_in_array(argc, argv, "-p", argc))
		extra->print_next_args = check_str_in_array(argc, argv, "-p", argc);
	if (check_str_in_array(argc, argv, "-t", extra->print_next_args))
	{
		extra->file_ended = 0;
		extra->from_txt = 1;
		extra->t_flag_position = check_str_in_array(argc, argv, "-t", argc);
		if (!ft_strnstr(argv[extra->t_flag_position], ".txt",
				ft_strlen(argv[extra->t_flag_position])))
			invalid_argument(0);
	}
	check_log_flags(extra, argc, argv, "client_log.log");
}

void	check_flags_server(t_extra *extra, int argc, char **argv)
{
	init_extra(extra);
	if (check_str_in_array(argc, argv, "-h", argc))
		return ((void)(extra->help = 1));
	if (check_str_in_array(argc, argv, "-c", argc))
		extra->print_c_by_c = 1;
	if (check_str_in_array(argc, argv, "-rbw", argc))
		(void)(init_rgb(&extra->rgb), extra->is_rbw = 1);
	check_log_flags(extra, argc, argv, "server_log.log");
}
