/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:13:00 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/15 22:43:49 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"


/// @brief Print with a rainbow effect str in terminal.
/// @param str Str to print.
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

/// @brief Print helper of server in terminal.
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

/// @brief Print helper of client in terminal.
void	print_help_client(void)
{
	ft_printf("\n%-10sPrint this helper. \
				\n%-10sGet input from a .txt file (but will have to print line by line). \
				\n%-10sPrint read characters in client_log.log. \
				\n%-10sPrint read characters (in binary and ASCII) \
in client_log.log. \
				\n%-10sPrint every char after this flag. \
				\n%-12c%s\n\n",
		"-h",
		"-t",
		"-l",
		"-lb",
		"-p",
		' ',
		"every arguments after this one will be taken as a separated string");
	exit(0);
}

/// @brief Exit the program and print str in terminal.
/// @param str Str to print,
/// @param status value the program return on exit.
void	ft_exit(char *str, int status)
{
	ft_printf("%s\n", str);
	exit(status);
}
