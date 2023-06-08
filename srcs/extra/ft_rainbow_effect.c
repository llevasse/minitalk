/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow_effect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:47:30 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/05 11:53:25 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	ft_rainbow_effect(t_rgb *rgb)
{
	when_red_top(rgb);
	if (rgb->g == 255)
	{
		rgb->g_top = 1;
		rgb->r_top = 0;
	}
	when_green_top(rgb);
	if (rgb->b == 255)
	{
		rgb->b_top = 1;
		rgb->g_top = 0;
	}
	when_blue_top(rgb);
	if (rgb->r == 255)
	{
		rgb->r_top = 1;
		rgb->b_top = 0;
	}
}

void	when_red_top(t_rgb *rgb)
{
	if (rgb->r_top)
	{
		if (rgb->b > 0)
			rgb->b--;
		else
			rgb->g++;
	}
}

void	when_green_top(t_rgb *rgb)
{
	if (rgb->g_top)
	{
		if (rgb->r > 0)
			rgb->r--;
		else
			rgb->b++;
	}
}

void	when_blue_top(t_rgb *rgb)
{
	if (rgb->b_top)
	{
		if (rgb->g > 0)
			rgb->g--;
		else
			rgb->r++;
	}
}
