/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_markdown.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:06:27 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/05 17:07:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_extra.h"

void	ft_put_markdown(t_extra *extra, unsigned char c)
{
	if (c == '*' && extra->md.bold_c_nb == 1 && extra->md.is_bold == 0)
	{
		extra->md.bold_c_nb = 2;
		return ((void)(write(1, "\x1B[1m", 5), extra->md.is_bold = 1));
	}
	if (c == '*' && extra->md.bold_c_nb == 1 && extra->md.is_bold == 1)
	{
		extra->md.bold_c_nb = 2;
		return ((void)(write(1, "\x1B[22m", 5), extra->md.is_bold = 0));
	}
	if (c == '*' && extra->md.bold_c_nb == 0)
		return ((void)(extra->md.bold_c_nb = 1));
	if (c == '_' && extra->md.bold_c_nb == 0 && extra->md.is_italic == 0)
		return ((void)(write(1, "\x1B[3m", 5), extra->md.is_italic = 1));
	if (c == '_' && extra->md.bold_c_nb == 0 && extra->md.is_italic == 1)
		return ((void)(write(1, "\x1B[23m", 5), extra->md.is_italic = 0));
	extra->md.bold_c_nb = 0;
	extra->md.stricketrough_c_nb = 0;
}