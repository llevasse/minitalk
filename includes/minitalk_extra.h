/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_extra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/30 14:08:41 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <signal.h>

void				send_str(int pid, char *str);
int					send_char(int pid, char c);
void				send_file(int pid, int fd);
void				ft_exit(char *str, int status);
int					use_file(int pid, char **argv);
void				handler(int sig, siginfo_t *siginfo, void *context);

typedef struct s_boolean_extra
{
	int						logged;
	int						binnary_logged;
	int						from_txt;
	int						signal_received;
}							t_boolean_extra;	

typedef struct s_sig_char
{
	int						shift;
	unsigned char			c;
	int						client_pid;
	t_boolean_extra			extra;
}							t_sig_char;

#endif