/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_get_next_line.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:59:20 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/11 10:38:31 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_GET_NEXT_LINE_H
# define U_GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1064
# endif

unsigned char	*get_next_line(int fd);
unsigned char	*check_stach_nl(unsigned char *stach,
					unsigned char buff[BUFFER_SIZE + 1], int fd);
unsigned char	*stach_empty(unsigned char *stach, int fd,
					unsigned char buff[BUFFER_SIZE]);
unsigned char	*return_line(unsigned char *stach[OPEN_MAX], int fd);
unsigned char	*ft_strjoin_free_first(unsigned char *s1, unsigned char *s2);
void			fill_char(unsigned char *dst, unsigned char *src, int till_nl);
size_t			ft_u_strlen(const unsigned char *str);
int				is_nl(const unsigned char *str);
void			get_left_over(unsigned char *line, unsigned char *stach);
void			clear_buff(unsigned char buff[BUFFER_SIZE]);
int				ft_u_strcmp(const unsigned char *s1, const unsigned char *s2);
void			ft_setzero(char *stach);
void			empty_buff(char buff[BUFFER_SIZE]);

#endif
