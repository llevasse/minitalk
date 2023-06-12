/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:13:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/12 11:54:50 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	ft_taste_the_rainbow(char *str)
{
	t_rgb	rgb;

	init_rgb(&rgb);
	rgb.offset = ft_strlen(str) * 2;
	while (*str)
	{
		print_color(&rgb);
		ft_printf("%c", *(str++));
	}
	ft_printf("\x1B[1;m");
}

void	print_help_server(void)
{
	ft_printf("\n%-10sPrint this helper. \
				\n%-10sPrint character when fully received, \
don't wait for whole str. \
				\n%-10sPrint read characters in server_log.log. \
				\n%-10sPrint read characters (in binary and ASCII) \
in server_log.log. \
				\n%-10s",
		"-h",
		"-c",
		"-l",
		"-lb",
		"-rbw");
	ft_taste_the_rainbow("Taste the rainbow!!!!!!!\n\n");
	exit(0);
}

void	print_help_client(void)
{
	ft_printf("\n%-10sPrint this helper. \
				\n%-10sGet input from a .txt file (but will have to print line by line). \
				\n%-10sPrint read characters in client_log.log. \
				\n%-10sPrint read characters (in binary and ASCII) \
in client_log.log.\n\n",
		"-h",
		"-t",
		"-l",
		"-lb");
	exit(0);
}

void	ft_exit(char *str, int status)
{
	ft_printf("%s\n", str);
	exit(status);
}
