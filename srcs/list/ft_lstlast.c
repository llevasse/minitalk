/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:47:30 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/31 13:08:41 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

t_mini_str	*ft_lstlast(t_mini_str *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
