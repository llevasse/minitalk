/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:57:39 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/11 10:39:35 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u_get_next_line.h"

unsigned char	*get_next_line(int fd)
{
	unsigned char			buff[BUFFER_SIZE + 1];
	static unsigned char	*stach[OPEN_MAX];
	unsigned char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || read(fd, buff, 0) != 0)
	{
		if (stach[fd])
			return (free(stach[fd]), stach[fd] = NULL, NULL);
		return (NULL);
	}
	buff[0] = 0;
	stach[fd] = stach_empty(stach[fd], fd, buff);
	if (!stach[fd] && buff[0] != 0)
		return (NULL);
	stach[fd] = check_stach_nl(stach[fd], buff, fd);
	if (!stach[fd])
		return (NULL);
	if (stach[fd][0] == '\0')
		return (free(stach[fd]), stach[fd] = NULL, NULL);
	line = return_line(stach, fd);
	if (!line)
		return (free(stach[fd]), stach[fd] = NULL, NULL);
	if (ft_u_strcmp(line, stach[fd]))
		return (get_left_over(line, stach[fd]), line);
	return (free(stach[fd]), stach[fd] = NULL, line);
}

unsigned char	*return_line(unsigned char *stach[OPEN_MAX], int fd)
{
	unsigned char	*line;
	int				i;

	i = 0;
	while (stach[fd][i] != '\n' && stach[fd][i])
		i++;
	line = malloc((i + is_nl(stach[fd]) + 1) * sizeof(unsigned char));
	if (!line)
		return (NULL);
	fill_char(line, stach[fd], is_nl(stach[fd]));
	return (line);
}

unsigned char	*stach_empty(unsigned char *stach, int fd,
		unsigned char buff[BUFFER_SIZE])
{
	int	count;

	if (stach)
		return (stach);
	count = read(fd, buff, BUFFER_SIZE);
	buff[count] = '\0';
	if (count < 0)
		return (NULL);
	stach = malloc((count + 1) * sizeof(unsigned char));
	if (!stach)
		return (NULL);
	stach[count] = '\0';
	fill_char(stach, buff, 0);
	return (stach);
}

unsigned char	*check_stach_nl(unsigned char *stach,
								unsigned char buff[BUFFER_SIZE + 1],
								int fd)
{
	int	count;

	if (!stach)
		return (stach);
	if (!is_nl(stach))
	{
		count = read(fd, buff, BUFFER_SIZE);
		buff[count] = '\0';
		while (!is_nl(stach) && count > 0)
		{
			stach = ft_strjoin_free_first(stach, buff);
			if (!stach)
				return (NULL);
			if (!is_nl(stach))
				count = read(fd, buff, BUFFER_SIZE);
			buff[count] = '\0';
		}
		if (count <= 0)
			stach = ft_strjoin_free_first(stach, (unsigned char *)"\0");
		if (!stach)
			return (NULL);
	}
	return (stach);
}

void	get_left_over(unsigned char *line, unsigned char *stach)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		stach[i++] = 0;
	if (!line[i])
		return (free(stach));
	i++;
	while (stach[i] != '\0')
		stach[j++] = stach[i++];
	stach[j] = 0;
}
