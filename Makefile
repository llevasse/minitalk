# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/03/20 22:45:44 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				=	-Wall -Werror -Wextra

SERV_FILES			=	srcs/server.c
CLIENT_FILES		=	srcs/client.c

SERV_OBJS			=	${SERV_FILES:.c=.o}
CLIENT_OBJS			=	${CLIENT_FILES:.c=.o}

%.o: %.c
					gcc ${FLAGS} -I includes -c $< -o ${<:.c=.o}

NAME				= minitalk.a

${NAME}:		${SERV_OBJS} includes/minitalk.h Makefile
					make -C libft 
					ar rcs srcs/server.a libft/libft.a ${SERV_OBJS}
					ar rcs srcs/client.a libft/libft.a ${CLIENT_OBJS}
					gcc server.a -o server
					gcc client.a -o client

all:			${NAME}

clean:
					make -C libft clean
					rm -f ${SERV_OBJS}
					rm -f ${CLIENT_OBJS}

fclean:			clean
				rm -rf srcs/server.a
				rm -rf srcs/client.a
re:				fclean all


.PHONY:			all clean fclean re
