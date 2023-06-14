/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_one_sig_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:23:15 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/14 16:30:12 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	ft_del_one_sig_c(t_sig_char *sig_char, int wanted_pid_del)
{
	int	temp_pid;

	if (sig_char->client_pid < wanted_pid_del && sig_char->next)
		ft_del_one_sig_c(sig_char->next, wanted_pid_del);
	if (sig_char->client_pid >= wanted_pid_del && sig_char->next)
	{
		sig_char = sig_char->next;
		ft_del_one_sig_c(sig_char->next, wanted_pid_del);
	}
	else if (sig_char->client_pid >= wanted_pid_del && !sig_char->next)
	{
		temp_pid = sig_char->extra->pid;
		sig_char->client_pid = temp_pid;
		sig_char->c = 0;
		sig_char->nb_null_received = 0;
		sig_char->shift = 7;
		sig_char->index_sig_char = 0;
		//free(sig_char);
		sig_char = NULL;
	}
}
