/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:22:34 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/21 11:27:07 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sig_handler(int signum)
{
	ft_printf("siguser1\n");
	ft_printf("signum : %i", signum);
}

int	main(void)
{
	__pid_t pid;
	
	signal(SIGUSR1, sig_handler);
	pid = getpid();
	ft_printf("pid : %i\n", pid);
	pause();
	
}
