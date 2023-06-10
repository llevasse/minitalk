/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:13:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/10 22:05:38 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	print_help_server(void)
{
	ft_printf("Help for server!!\n");
	exit(0);
}

void	print_help_client(void)
{
	ft_printf("\n%-10sPrint this helper. \
				\n%-10sGet input from a file (.txt). \
				\n%-10sPrint read characters in client_log.log. \
				\n%-10sPrint read characters (in binary and ASCII) \
in client_log.log.\n\n",
		"-h",
		"-t",
		"-l",
		"-lb");
	exit(0);
}
