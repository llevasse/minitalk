/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/05 15:27:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	ft_lstprint(t_mini_str *lst, t_boolean_extra *extra)
{
	if (!lst)
		return ;
	if (extra->is_rbw && lst->c <= 127)
		print_color(&extra->rgb);
	print_log(*extra, lst->c);
	write(1, &lst->c, 1);
	if (lst->next)
		ft_lstprint(lst->next, extra);
	free(lst);
	lst = NULL;
}

void	print_binary(char c, int fd)
{
	int	size_char;

	size_char = -1;
	while (size_char++ < 7)
	{
		if (!!((c << size_char) & 0x80))
			write(fd, "1", 1);
		else
			write(fd, "0", 1);
	}
}
