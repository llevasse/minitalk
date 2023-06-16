/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_extra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/16 17:27:06 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_EXTRA_H
# define MINITALK_EXTRA_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <signal.h>

typedef struct s_rgb
{
	int					offset;
	int					r;
	int					r_top;
	char				*r_str;
	int					g;
	int					g_top;
	char				*g_str;
	int					b;
	int					b_top;
	char				*b_str;
}						t_rgb;

typedef struct s_extra
{
	int					print_next_args;
	int					file_ended;
	int					line_index;
	int					help;
	int					logged;
	int					binnary_logged;
	int					log_fd;
	int					from_txt;
	int					t_flag_position;
	int					print_c_by_c;
	int					is_rbw;
	struct s_rgb		rgb;
}						t_extra;

typedef struct s_mini_str
{
	unsigned char		c;
	struct s_mini_str	*next;
}						t_mini_str;

typedef struct s_sig_char
{
	int					nb_null_received;
	int					shift;
	unsigned char		c;
	int					client_pid;
	int					server_pid;
	int					need_set_pid;
	t_mini_str			*mini_str;
	t_extra				extra;
}						t_sig_char;

/* FT_SEND_EXTRA.C */
void					send_file(int pid, int fd, t_extra *extra);
void					send_str(int pid, char *str, t_extra extra);
int						send_char(int pid, char c, t_extra extra);

/* SIG_CHAR.C */
void					print_sig_char(siginfo_t *siginfo,
							t_sig_char *sig_char);
void					print_single_char(unsigned char c,
							t_sig_char *sig_char);
void					receive_null(siginfo_t *siginfo, t_sig_char *sig_char);

/* INIT.C */
void					init_rgb(t_rgb *rgb);
void					init_extra(t_extra *extra);
void					init_client(t_extra *extra, int argc, char **argv,
							int *pid);
void					init_server(t_extra *extra, int argc, char **argv,
							t_sig_char *sig_char);

/* EXTRA.C */
void					invalid_argument(void);

void					check_flags_client(t_extra *extra, int agrc,
							char **argv);
void					check_flags_server(t_extra *extra, int agrc,
							char **argv);
int						check_str_in_array(int argc, char **ar, const char *str,
							int len_ar);
void					ft_exit(char *str, int status);
void					check_only_flags(t_extra *extra, int argc, char **argv);

/* LOG.C */
void					print_log(t_extra extra, unsigned char c);
void					check_log_flags(t_extra *extra, int argc, char **argv,
							char *file_name);

/* FT_LSTPRINT_EXTRA.C */
void					ft_lstprint_extra(t_mini_str *lst,
							t_extra *extra);
void					print_binary(unsigned char c, int fd);

/* EXTRA_COLOUR.C */
void					free_rgb(t_rgb *rgb, char *str);
void					get_rgb_as_str(t_rgb *rgb);
char					*get_escape_c(t_rgb *rgb);
void					print_color(t_rgb *rgb);

/* FT_RAINBOW_EFFECT */
void					ft_rainbow_effect(t_rgb *rgb);
void					when_red_top(t_rgb *rgb);
void					when_green_top(t_rgb *rgb);
void					when_blue_top(t_rgb *rgb);

/* HELP.C */
void					print_help_client(void);
void					print_help_server(void);

/* {function_name}.C */
void					ft_lstclear(t_mini_str **lst);
void					ft_lstadd_back(t_mini_str **lst, t_mini_str *new);
t_mini_str				*ft_lstnew(unsigned char c);

#endif