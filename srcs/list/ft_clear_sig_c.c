/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_sig_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:56:13 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/14 10:58:45 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	free_last(t_sig_char *lst);

void	ft_clear_sig_c(t_sig_char **lst)
{
	t_sig_char	*temp;

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

void	free_last(t_sig_char *lst)
{
	t_sig_char	*temp;

	temp = lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}
