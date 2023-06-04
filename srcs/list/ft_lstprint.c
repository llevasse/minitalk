/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/04 12:58:59 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	ft_lstprint(t_mini_str *lst, t_boolean_extra *extra)
{
	if (!lst)
		return ;
	if (extra->is_rbw)
		print_color(&extra->rgb, lst->c);
	write(1, &lst->c, 1);
	if (lst->next)
		ft_lstprint(lst->next, extra);
	free(lst);
	lst = NULL;
}
