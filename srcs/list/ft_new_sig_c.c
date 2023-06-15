/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sig_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:59:41 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/15 14:09:44 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

t_sig_char	*ft_new_sig_c(int pid, t_extra *extra, unsigned index_sig)
{
	struct s_sig_char	*new_el;

	new_el = malloc(sizeof(struct s_sig_char));
	if (!new_el)
		return (NULL);
	new_el->client_pid = pid;
	new_el->c = 0;
	new_el->shift = 7;
	new_el->mini_str = NULL;
	new_el->next = NULL;
	new_el->nb_null_received = 0;
	new_el->extra = extra;
	new_el->index_sig_char = index_sig;
	return (new_el);
}
