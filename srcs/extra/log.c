/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:21:49 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/05 15:27:03 by llevasse         ###   ########.fr       */
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
