/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:32:06 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/04 16:01:51 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

// rainbow effect : when R == 255, start increasing G
//					when G == 255, start decreasing R
//					when R == 0, start increasing B;
//					when B == 255, start decreasing G;
//					when G == 0, start increasing R;
//					when R == 255,start decreasing B;
//					repeat

void	free_rgb(t_rgb *rgb, char *str)
{
	if (rgb->r_str)
		free(rgb->r_str);
	if (rgb->g_str)
		free(rgb->g_str);
	if (rgb->b_str)
		free(rgb->b_str);
	if (str)
		free(str);
}

char	*get_color_str(t_rgb *rgb)
{
	char	*str;
	char	*temp;

	str = NULL;
	rgb->r_str = ft_itoa(rgb->r);
	if (!rgb->r_str)
		return (NULL);
	rgb->g_str = ft_itoa(rgb->g);
	if (!rgb->g_str)
		return (free_rgb(rgb, str), NULL);
	rgb->b_str = ft_itoa(rgb->b);
	if (!rgb->b_str)
		return (free_rgb(rgb, str), NULL);
	str = ft_strjoin("\x1B[38;2;", rgb->r_str);
	if (!str)
		return (free_rgb(rgb, str), NULL);
	temp = ft_strjoin(str, ";");
	if (temp)
		free(str);
	else
		return (free_rgb(rgb, str), NULL);
	str = ft_strjoin(temp, rgb->g_str);
	if (!str)
		return (free_rgb(rgb, temp), NULL);
	else
		free(temp);
	temp = ft_strjoin(str, ";");
	if (temp)
		free(str);
	else
		return (free_rgb(rgb, str), NULL);
	str = ft_strjoin(temp, rgb->b_str);
	if (!str)
		return (free_rgb(rgb, temp), NULL);
	else
		free(temp);
	temp = ft_strjoin(str, "m");
	if (temp)
		free(str);
	else
		return (free_rgb(rgb, str), NULL);
	return (temp);
}

void	print_color(t_rgb *rgb, unsigned char c)
{
	char	*str;

	(void)c;
	str = get_color_str(rgb);
	if (!str)
		return ;
	ft_printf("%s", str);
	free(str);
	if (rgb->r_top)
	{
		if (rgb->b > 0)
			rgb->b--;
		else
			rgb->g++;
	}
	if (rgb->g == 255)
	{
		rgb->g_top = 1;
		rgb->r_top = 0;
	}
	if (rgb->g_top)
	{
		if (rgb->r > 0)
			rgb->r--;
		else
			rgb->b++;
	}
	if (rgb->b == 255)
	{
		rgb->b_top = 1;
		rgb->g_top = 0;
	}
	if (rgb->b_top)
	{
		if (rgb->g > 0)
			rgb->g--;
		else
			rgb->r++;
	}
	if (rgb->r == 255)
	{
		rgb->r_top = 1;
		rgb->b_top = 0;
	}
}
