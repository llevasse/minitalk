/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 13:18:42 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_lstprint(t_mini_str **lst)
{
	if (*lst)
	{
		while ((*lst)->next != NULL)
		{
			write(1, &(*lst)->c, 1);
			*lst = (*lst)->next;
		}
	}
}