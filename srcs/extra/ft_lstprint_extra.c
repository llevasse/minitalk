/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:11:42 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/16 15:48:21 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

/// @brief Print every char in chained list and free it.
/// @param lst pointer to mini_str structur,
/// @param extra pointer to extra structur.
void	ft_lstprint_extra(t_mini_str *lst, t_extra *extra)
{
	if (!lst)
		return ;
	if (extra->is_rbw && lst->c <= 127)
		print_color(&extra->rgb);
	if (extra->logged)
		print_log(*extra, lst->c);
	write(1, &lst->c, 1);
	if (lst->next)
		ft_lstprint_extra(lst->next, extra);
	lst->next = NULL;
	free(lst);
	lst = NULL;
}

/// @brief Print binary of char at fd.
/// @param c character being printed,
/// @param fd file descriptor.
void	print_binary(unsigned char c, int fd)
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
