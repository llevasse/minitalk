/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:21:49 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/16 16:02:17 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

/// @brief Print char in log file.
/// @param extra Pointer to extra structur,
/// @param c Character to print.
void	print_log(t_extra extra, unsigned char c)
{
	if (c <= 127)
	{
		if (extra.binnary_logged == 1 && c != '\0')
			write(extra.log_fd, "-{", 2);
		if (extra.binnary_logged == 1 && c != '\0')
			print_binary(c, extra.log_fd);
		if (extra.binnary_logged == 1 && c != '\0')
			write(extra.log_fd, ",", 1);
		if (extra.logged == 1 && c != '\0')
			write(extra.log_fd, &c, 1);
		if (extra.binnary_logged == 1 && c != '\0')
			write(extra.log_fd, "}-", 2);
	}
	else if (c > 127 && extra.logged)
		write(extra.log_fd, &c, 1);
}

/// @brief Get and assign log flags to t_extra.
/// @param extra Pointer to extra structur,
/// @param argc Nb of element in argv,
/// @param argv Elements given to the program,
/// @param file_name name of the file to open/create for logs.
void	check_log_flags(t_extra *extra, int argc, char **argv, char *file_name)
{
	if (check_str_in_array(argc, argv, "-l", extra->print_next_args))
	{
		extra->log_fd = open(file_name, O_RDWR | O_CREAT, 0666);
		extra->logged = 1;
		extra->print_c_by_c = 1;
	}
	else if (check_str_in_array(argc, argv, "-lb", extra->print_next_args))
	{
		extra->log_fd = open(file_name, O_RDWR | O_CREAT, 0666);
		extra->print_c_by_c = 1;
		extra->logged = 1;
		extra->binnary_logged = 1;
		//write(extra->log_fd, "{", 1);
	}
}
