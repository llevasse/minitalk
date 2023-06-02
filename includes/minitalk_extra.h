/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_extra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/02 14:58:02 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_EXTRA_H
# define MINITALK_EXTRA_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <signal.h>

typedef struct s_boolean_extra
{
	int					logged;
	int					binnary_logged;
	int					log_fd;
	int					from_txt;
	int					t_flag_position;
	int					str_position;
	int					print_c_by_c;
	int					rgb;
}						t_boolean_extra;

typedef struct s_mini_str
{
	unsigned char		c;
	struct s_mini_str	*next;
}						t_mini_str;

typedef struct s_sig_char
{
	int					shift;
	unsigned char		c;
	int					client_pid;
	t_mini_str			*mini_str;
	t_boolean_extra		extra;
}						t_sig_char;

void					send_str(int pid, char *str, t_boolean_extra extra);
int						send_char(int pid, char c, t_boolean_extra extra);
void					send_file(int pid, int fd, t_boolean_extra extra);
int						log_char(int pid, t_boolean_extra extra, int sig);
void					ft_exit(char *str, int status);
void					handler(int sig, siginfo_t *siginfo, void *context);
int						invalid_argument(int status);
void					print_sig_char(siginfo_t *siginfo);
void					print_color(int *color);

void	check_n_get_flags_client(t_boolean_extra *extra,
								int agrc,
								char **argv);
void	check_n_get_flags_server(t_boolean_extra *extra,
								int agrc,
								char **argv);
int						check_str_in_array(int argc, char **ar, const char *str,
							int len_ar);

t_mini_str				*ft_lstlast(t_mini_str *lst);
void					ft_lstclear(t_mini_str **lst);
void					ft_lstadd_back(t_mini_str **lst, t_mini_str *new);
int						ft_lstsize(t_mini_str *lst);
void					ft_lstadd_front(t_mini_str **lst, t_mini_str *new);
t_mini_str				*ft_lstnew(unsigned char c);
void					ft_lstprint(t_mini_str *lst, int *color);

void					ft_exit(char *str, int status);

#endif