/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_extra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/06 14:26:22 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_EXTRA_H
# define MINITALK_EXTRA_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <signal.h>

typedef struct s_rgb
{
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

typedef struct s_markdown
{
	int					backslash;
	int					char_since_backslash;
	int					bold_c_nb;
	int					is_bold;
	int					stricketrough_c_nb;
	int					is_stricketrough;
	int					is_italic;
}						t_md;

typedef struct s_boolean_extra
{
	int					use_markdown;
	int					logged;
	int					binnary_logged;
	int					log_fd;
	int					from_txt;
	int					t_flag_position;
	int					str_position;
	int					print_c_by_c;
	struct s_rgb		rgb;
	struct s_markdown	md;
	int					is_rbw;
	int					help;
}						t_extra;

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
	t_extra				extra;
}						t_sig_char;

void					send_str(int pid, char *str, t_extra extra);
int						send_char(int pid, char c, t_extra extra);
void					send_file(int pid, int fd, t_extra extra);
int						log_char(int pid, t_extra extra, int sig);
void					ft_exit(char *str, int status);
void					handler(int sig, siginfo_t *siginfo, void *context);
int						invalid_argument(int status);
void					print_sig_char(siginfo_t *siginfo);
void					print_color(t_rgb *rgb);
void					init_rgb(t_extra *extra);
void					ft_rainbow_effect(t_rgb *rgb);
void					when_red_top(t_rgb *rgb);
void					when_green_top(t_rgb *rgb);
void					when_blue_top(t_rgb *rgb);
void					print_log(t_extra extra, unsigned char c);
void					ft_put_markdown(t_extra *extra, unsigned char c);

void	check_n_get_flags_client(t_extra *extra,
								int agrc,
								char **argv);
void	check_n_get_flags_server(t_extra *extra,
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
void					ft_lstprint_extra(t_mini_str *lst, t_extra *extra);
void					print_binary(char c, int fd);

void					ft_exit(char *str, int status);

void					print_help_client(void);
void					print_help_server(void);

#endif