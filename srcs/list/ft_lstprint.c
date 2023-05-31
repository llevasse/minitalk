/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 13:32:02 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_lstprint(t_mini_str *lst)
{
	if (!lst)
		return ;
	write(1, &lst->c, 1);
	if (lst->next)
		ft_lstprint(lst->next);
}