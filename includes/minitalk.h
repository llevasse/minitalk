/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:56:24 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/07 12:53:23 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <signal.h>

void					send_str(int pid, unsigned char *str);
int						send_char(int pid, unsigned char c);
void					send_file(int pid, int fd);
void					ft_exit(char *str, int status);
int						use_file(int pid, char **argv);
void					handler(int sig, siginfo_t *siginfo, void *context);

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
}						t_sig_char;

t_mini_str				*ft_lstlast(t_mini_str *lst);
void					ft_lstclear(t_mini_str **lst);
void					ft_lstadd_back(t_mini_str **lst, t_mini_str *new);
int						ft_lstsize(t_mini_str *lst);
void					ft_lstadd_front(t_mini_str **lst, t_mini_str *new);
t_mini_str				*ft_lstnew(unsigned char c);
void					ft_lstprint(t_mini_str *lst);
#endif