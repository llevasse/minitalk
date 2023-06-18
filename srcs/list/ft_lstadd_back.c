/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:50:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/18 21:03:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

/// @brief Add new element at the end of a list of mini_str.
/// @param lst Pointer to list of mini_str structur,
/// @param new Pointer to mini_str being added.
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
