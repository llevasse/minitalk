/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:41:46 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/24 12:48:03 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// I know it wasn't asked as a bonus, but, BUT, for readability with huge text,
// I want to implement a "-t" flag that would indicate that the client need to read from a .txt file

int	main(int argc, char **argv)
{
	__pid_t	pid;

	if (argc != 3 && argc != 4)
	{
		ft_printf("Error. Invalid argument\n");
		ft_printf("sould be : ./client {pid} \"{string}\"\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (argc == 4)
	{
		if (ft_strcmp(argv[2], "-t") || !ft_strnstr(argv[3], ".txt",
				ft_strlen(argv[3])))
		{
			ft_printf("Error. Invalid argument\n");
			ft_printf("sould be : ./client {pid} -t {file.txt} \n");
			return (1);
		}
		send_file(pid, open(argv[3], O_RDONLY));
	}
	if (argc == 3)
	{
		ft_printf("client pid : %i\n", getpid());
		send_str(pid, argv[2]);
	}
}

/* print char as binary

c = 'a'
size_char = 8
while (size_char-- > 0)
{
	ft_printf("%i", !!((c << 1) & 0x80))
	c <<= 1
}

*/

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR1)
		write(1, "", 1);
	if (sig == SIGUSR2)
		ft_printf("Str printed\n");
	(void)context;
	(void)siginfo;
}

void	send_file(int pid, int fd)
{
	char	*str;
	char	*temp;

	str = get_next_line(fd);
	while (str)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		str = ft_strjoin(str, temp);
		free(temp);
	}
	if (str)
	{
		send_str(pid, str);
		free(str);	
	}
	close(fd);
}

void	send_str(int pid, char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		send_char(pid, str[i++]);
	send_char(pid, '\n');
	send_char(pid, '\0');
}

void	send_char(int pid, char c)
{
	int					size_char;
	struct sigaction	sa;

	size_char = -1;
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR2, &sa, NULL) < 0 || sigaction(SIGUSR1, &sa, NULL) < 0)
	{
		ft_printf("sigaction");
		return ;
	}
	while (size_char++ < 7)
	{
		if (!!((c << size_char) & 0x80))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
	}
}
