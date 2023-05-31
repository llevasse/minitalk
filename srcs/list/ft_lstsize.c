/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:41:40 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 11:45:08 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	ft_lstsize(t_mini_str *lst)
{
	int	i;

	if (lst)
	{
		i = 1;
		while (lst->next != NULL)
		{
			lst = lst->next;
			i++;
		}
		return (i);
	}
	return (0);
}
