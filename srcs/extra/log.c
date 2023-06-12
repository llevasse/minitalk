/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:21:49 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/12 15:41:14 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	print_log(t_boolean_extra extra, unsigned char c)
{
	if (extra.binnary_logged == 1)
		print_binary(c, extra.log_fd);
	if (extra.binnary_logged == 1 && c != '\0')
		write(extra.log_fd, ",", 1);
	if (extra.logged == 1 && c != '\0')
		write(extra.log_fd, &c, 1);
	if (extra.binnary_logged == 1 && c != '\0')
		write(extra.log_fd, "}-{", 3);
	else if (extra.binnary_logged == 1 && c == '\0')
		write(extra.log_fd, "}", 1);
}

void	check_log_flags(t_boolean_extra *extra, int argc, char **argv,
		char *file_name)
{
	if (check_str_in_array(argc, argv, "-l", extra->print_next_args))
	{
		extra->log_fd = open(file_name, O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
	}
	else if (check_str_in_array(argc, argv, "-lb", extra->print_next_args))
	{
		extra->log_fd = open(file_name, O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
		extra->binnary_logged = 1;
		write(extra->log_fd, "{", 1);
	}
}
