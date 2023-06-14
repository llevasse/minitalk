/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sig_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:59:41 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/14 11:04:01 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

t_sig_char	*ft_new_sig_c(int pid, t_boolean_extra *extra, unsigned index_sig)
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

void	connect_temp(int wanted_pid, t_sig_char *sig_char, t_sig_char *temp)
{
	temp = sig_char;
	while (sig_char->next)
	{
		if (temp->client_pid == wanted_pid)
			return ;
		else
			temp = temp->next;
	}
	ft_add_back_sig_c(&temp, ft_new_sig_c(wanted_pid, sig_char->extra,
				temp->index_sig_char + 1));
	temp = temp->next;
}
