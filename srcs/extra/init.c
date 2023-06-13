/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:08:29 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/13 17:10:16 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

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

void	init_extra(t_boolean_extra *extra)
{
	extra->print_next_args = 0;
	extra->file_ended = 1;
	extra->line_index = 0;
	extra->help = 0;
	extra->logged = 0;
	extra->binnary_logged = 0;
	extra->log_fd = 0;
	extra->from_txt = 0;
	extra->t_flag_position = 0;
	extra->print_c_by_c = 0;
	extra->is_rbw = 0;
}
