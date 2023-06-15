/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:08:29 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/15 14:09:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	init_client(t_extra *extra, int argc, char **argv, int *pid)
{
	check_flags_client(extra, argc, argv);
	if (extra->help)
		print_help_client();
	if (argc <= 2)
		invalid_argument(argv[1]);
	*pid = ft_atoi(argv[1]);
	if (*pid == 0)
		ft_exit("Invalid pid", 1);
}

void	init_server(t_extra *extra, int argc, char **argv,
		t_sig_char *sig_char)
{
	__pid_t	pid;

	if (argc > 1 && !ft_strcmp("-h", argv[1]))
		print_help_server();
	pid = getpid();
	ft_printf("pid : %i\n", pid);
	check_flags_server(extra, argc, argv);
	sig_char->shift = 7;
	sig_char->mini_str = NULL;
	sig_char->extra = *extra;
	sig_char->need_set_pid = 1;
	sig_char->client_pid = pid;
	sig_char->server_pid = pid;
}

void	init_rgb(t_rgb *rgb)
{
	rgb->offset = 1;
	rgb->r = 255;
	rgb->r_top = 1;
	rgb->g = 0;
	rgb->g_top = 0;
	rgb->b = 0;
	rgb->b_top = 0;
}

void	init_extra(t_extra *extra)
{
	extra->print_next_args = 0;
	extra->file_ended = 1;
	extra->line_index = 0;
	extra->help = 0;
	extra->logged = 0;
	extra->binnary_logged = 0;
	extra->log_fd = -1;
	extra->from_txt = 0;
	extra->t_flag_position = 0;
	extra->print_c_by_c = 0;
	extra->is_rbw = 0;
}
