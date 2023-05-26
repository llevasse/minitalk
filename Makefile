# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/05/26 23:07:02 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				=	-Wall -Werror -Wextra

CC					=	cc

SERV_FILES			=	srcs/server.c
CLIENT_FILES		=	srcs/client.c

SERV_OBJS			=	$(SERV_FILES:.c=.o)
CLIENT_OBJS			=	$(CLIENT_FILES:.c=.o)

%.o: %.c
					$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

NAME				= minitalk

$(NAME):		$(SERV_OBJS) $(CLIENT_OBJS) includes/minitalk.h Makefile
					make -C libft
					cp libft/libft.a srcs/server.a
					cp libft/libft.a srcs/client.a
					ar rcs srcs/server.a $(SERV_OBJS)
					ar rcs srcs/client.a $(CLIENT_OBJS)
					$(CC) -g srcs/server.a -o server
					$(CC) -g srcs/client.a -o client

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
