/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_extra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/12 15:24:15 by llevasse         ###   ########.fr       */
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

typedef struct s_boolean_extra
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
	unsigned			index;
	t_mini_str			*mini_str;
	t_boolean_extra		extra;
}						t_sig_char;

/* FT_SEND_EXTRA.C */
void					send_file(int pid, int fd, t_boolean_extra *extra);
void					send_str(int pid, char *str, t_boolean_extra extra);
int						send_char(int pid, char c, t_boolean_extra extra);

/* SERVER_EXTRA.C */
void					print_sig_char(siginfo_t *siginfo);

/* EXTRA.C */
int						invalid_argument(char *str);
void					check_log_flags(t_boolean_extra *extra, int argc,
							char **argv, char *file_name);

void	check_n_get_flags_client(t_boolean_extra *extra,
								int agrc,
								char **argv);
void	check_n_get_flags_server(t_boolean_extra *extra,
								int agrc,
								char **argv);
int						check_str_in_array(int argc, char **ar, const char *str,
							int len_ar);
void					ft_exit(char *str, int status);

/* LOG.C */
void					print_log(t_boolean_extra extra, unsigned char c);

/* FT_LSTPRINT_EXTRA.C */
void	ft_lstprint_extra(t_mini_str *lst,
						t_boolean_extra *extra);
void					print_binary(char c, int fd);

/* EXTRA_COLOUR.C */
void					free_rgb(t_rgb *rgb, char *str);
void					init_rgb(t_rgb *rgb);
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