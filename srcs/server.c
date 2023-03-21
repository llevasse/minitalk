/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/21 23:03:27 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("0");
	if (signum == SIGUSR2)
		ft_printf("1");
}

int	main(void)
{
	int		char_size;
	__pid_t	pid;

	pid = getpid();
	
	ft_printf("pid : %i\n", pid);
	char_size = 0;
	while (char_size < 7)
	{
		if (signal(SIGUSR1, sig_handler) == SIG_ERR)
			exit(1);
		if (signal(SIGUSR2, sig_handler) == SIG_ERR)
			exit(1);
		pause();
	}
}
