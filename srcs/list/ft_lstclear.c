/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:56:13 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 13:08:59 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	free_last(t_mini_str *lst);

void	ft_lstclear(t_mini_str **lst)
{
	t_mini_str	*temp;

	if (*lst)
	{
		temp = *lst;
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		while (temp->next != NULL)
			free_last(temp);
		free(temp);
	}
	*lst = NULL;
	return ;
}

void	free_last(t_mini_str *lst)
{
	t_mini_str	*temp;

	temp = lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}
