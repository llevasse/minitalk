/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/16 14:05:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <signal.h>

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
}						t_sig_char;

/* CLIENT.C */
void					test_serv(int pid);

/* FT_SEND.C */
void					send_str(int pid, char *str);
int						send_char(int pid, char c);
void					ft_exit(char *str, int status);

/* SERVER.C */
void					print_sig_char(siginfo_t *siginfo);
void					receive_null(siginfo_t *siginfo);

/* {function_name}.C */
void					ft_lstclear(t_mini_str **lst);
void					ft_lstadd_back(t_mini_str **lst, t_mini_str *new);
t_mini_str				*ft_lstnew(unsigned char c);
void					ft_lstprint(t_mini_str *lst);

#endif