/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/02 18:18:26 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	ft_lstprint(t_mini_str *lst, t_rgb *color)
{
	if (!lst)
		return ;
	print_color(color);
	write(1, &lst->c, 1);
	if (lst->next)
		ft_lstprint(lst->next, color);
	free(lst);
	lst = NULL;
}
