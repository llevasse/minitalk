/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:50:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 22:18:16 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_lstadd_back(t_mini_str **lst, t_mini_str *new)
{
	t_mini_str	*temp;

	if (!new)
	{
		if (*lst)
			ft_lstclear(lst);
	}
	if (*lst)
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return ;
	}
	*lst = new;
}
