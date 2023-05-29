# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/05/29 15:31:37 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				=	-Wall -Werror -Wextra

CC					=	cc

SERV_FILES			=	srcs/server.c
CLIENT_FILES		=	srcs/client.c \
						srcs/ft_send.c

SERV_OBJS			=	$(SERV_FILES:.c=.o)
CLIENT_OBJS			=	$(CLIENT_FILES:.c=.o)

%.o: %.c
					$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

NAME				= minitalk

$(NAME):		$(SERV_OBJS) $(CLIENT_OBJS) includes/minitalk.h Makefile
					make -C libft
					$(CC) -g $(SERV_OBJS) libft/libft.a -o server
					$(CC) -g $(CLIENT_OBJS) libft/libft.a -o client

all:			$(NAME)

clean:
					make -C libft clean
					rm -f $(SERV_OBJS)
					rm -f $(CLIENT_OBJS)

fclean:			clean
				make -C libft fclean
				rm -rf srcs/server.a srcs/client.a client server
				
re:				fclean all


.PHONY:			all clean fclean re
