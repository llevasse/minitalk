/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:32:06 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/04 21:30:54 by llevasse         ###   ########.fr       */
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
	{
		free(rgb->r_str);
		rgb->r_str = NULL;
	}
	if (rgb->g_str)
	{
		free(rgb->g_str);
		rgb->g_str = NULL;
	}
	if (rgb->b_str)
	{
		free(rgb->b_str);
		rgb->b_str = NULL;
	}
	if (str)
		free(str);
}

void	init_rgb(t_boolean_extra *extra)
{
	extra->is_rbw = 1;
	extra->rgb.r = 255;
	extra->rgb.r_top = 1;
	extra->rgb.g = 0;
	extra->rgb.g_top = 0;
	extra->rgb.b = 0;
	extra->rgb.b_top = 0;
}

void	get_rgb_as_str(t_rgb *rgb)
{
	rgb->r_str = ft_strjoin(ft_itoa(rgb->r), ";");
	if (!rgb->r_str)
		return (free_rgb(rgb, NULL));
	rgb->g_str = ft_strjoin(ft_itoa(rgb->g), ";");
	if (!rgb->g_str)
		return (free_rgb(rgb, NULL));
	rgb->b_str = ft_strjoin(ft_itoa(rgb->b), "m");
	if (!rgb->b_str)
		return (free_rgb(rgb, NULL));
}

char	*get_escape_c(t_rgb *rgb)
{
	char	*str;
	char	*temp;

	get_rgb_as_str(rgb);
	if (!rgb->r_str)
		return (NULL);
	str = ft_strjoin("\x1B[38;2;", rgb->r_str);
	if (!str)
		return (free_rgb(rgb, str), NULL);
	temp = ft_strjoin(str, rgb->g_str);
	if (!temp)
		return (free_rgb(rgb, str), NULL);
	else
		free(str);
	str = ft_strjoin(temp, rgb->b_str);
	if (!str)
		return (free_rgb(rgb, temp), NULL);
	else
		free(temp);
	return (str);
}

void	print_color(t_rgb *rgb, unsigned char c)
{
	char	*str;

	(void)c;
	str = get_escape_c(rgb);
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
