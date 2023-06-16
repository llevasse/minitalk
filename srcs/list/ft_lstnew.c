/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:07:45 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/16 11:06:15 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

/// @brief Create and assign char to new mini_str.
/// @param c Unsigned char to assign to new element.
/// @return Pointer to new mini_str.
t_mini_str	*ft_lstnew(unsigned char c)
{
	struct s_mini_str	*new_el;

	new_el = malloc(sizeof(struct s_mini_str));
	if (!new_el)
		return (NULL);
	new_el->c = c;
	new_el->next = NULL;
	return (new_el);
}
