/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_get_next_line_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:58:13 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/07 12:55:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u_get_next_line.h"

int	is_nl(const unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

size_t	ft_u_strlen(const unsigned char *str)
{
	unsigned long	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned char	*ft_strjoin_free_first(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	joined = malloc((ft_u_strlen(s1) + ft_u_strlen(s2)) * sizeof(unsigned char) + 1);
	if (!joined)
		return (free(s1), NULL);
	while (s1[i] != '\0')
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (free(s1), joined);
}

int	ft_u_strcmp(const unsigned char *s1, const unsigned char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	fill_char(unsigned char *dst, unsigned char *src, int till_nl)
{
	int	i;

	i = 0;
	if (!src)
		dst[0] = '\0';
	else if (!till_nl)
	{
		while (src[i] > 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (src[i] > 0 && src[i] != '\n')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = src[i];
		dst[i + 1] = 0;
	}
}
