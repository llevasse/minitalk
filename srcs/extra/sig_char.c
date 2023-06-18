/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:55:49 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/18 13:01:41 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_extra.h"

/// @brief Print char currently in sig_char.
/// @param c Character to print,
/// @param sig_char Pointer to sig_char structur.
void	print_single_char(unsigned char c, t_sig_char *sig_char)
{
	if (sig_char->extra.is_rbw && c <= 127)
		print_color(&sig_char->extra.rgb);
	print_log(sig_char->extra, c);
	write(1, &sig_char->c, 1);
}

/// @brief Reset sig_char or print sig_char->mini_str.
/// @param siginfo Pointer to siginfo structur,
/// @param sig_char Pointer to sig_char structur.
void	print_sig_char(siginfo_t *siginfo, t_sig_char *sig_char)
{
	if (sig_char->shift >= 0)
		return ;
	if (sig_char->c == '\0')
		receive_null(siginfo, sig_char);
	if (sig_char->extra.print_c_by_c == 0)
	{
			if (!sig_char->mini_str)
				sig_char->mini_str = ft_lstnew(sig_char->c);
			else
				ft_lstadd_back(&sig_char->mini_str, ft_lstnew(sig_char->c));
	}
	else
		print_single_char(sig_char->c, sig_char);
	sig_char->shift = 7;
	sig_char->c = 0;
}

/// @brief Handle first tests signals and print sig_char->mini_str.
/// @param siginfo Pointer to siginfo structur,
/// @param sig_char Pointer to sig_char structur.
void	receive_null(siginfo_t *siginfo, t_sig_char *sig_char)
{
	if (sig_char->nb_null_received++ >= 1)
	{
		if (sig_char->extra.print_c_by_c == 0)
			ft_lstprint_extra(sig_char->mini_str, &sig_char->extra);
		sig_char->mini_str = NULL;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			ft_exit("Error in sending signal", 1);
		sig_char->need_set_pid = 1;
		sig_char->nb_null_received = 0;
	}
}
