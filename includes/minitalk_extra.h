/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_extra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/30 15:11:54 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <signal.h>

typedef struct s_boolean_extra
{
	int				logged;
	int				binnary_logged;
	int				from_txt;
	int				t_flag_position;
	int				signal_received;
}					t_boolean_extra;

typedef struct s_sig_char
{
	int				shift;
	unsigned char	c;
	int				client_pid;
	t_boolean_extra	extra;
}					t_sig_char;

void				send_str(int pid, char *str);
int					send_char(int pid, char c);
void				send_file(int pid, int fd);
void				ft_exit(char *str, int status);
int					use_file(int pid, char **argv);
void				handler(int sig, siginfo_t *siginfo, void *context);
int					invalid_argument(int status);

void				check_n_get_flags(t_boolean_extra *extra, int agrc,
						char **argv);
int					check_str_in_array(int argc, char **ar, const char *str,
						int len_ar);

#endif