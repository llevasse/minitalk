/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/16 11:04:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

/// @brief Print every char in chained list and free it.
/// @param lst pointer to mini_str structur.
void	ft_lstprint(t_mini_str *lst)
{
	if (!lst)
		return ;
	write(1, &lst->c, 1);
	if (lst->next)
		ft_lstprint(lst->next);
	free(lst);
	lst = NULL;
}
