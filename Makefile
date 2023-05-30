# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/05/30 22:15:34 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				=	-Wall -Werror -Wextra

CC					=	cc

SERV_FILES			=	srcs/server.c
CLIENT_FILES		=	srcs/client.c \
						srcs/ft_send.c


EXTRA_SERV_FILES	=	srcs/extra/server_extra.c
EXTRA_CLIENT_FILES	=	srcs/extra/client_extra.c \
						srcs/extra/ft_send_extra.c
EXTRA_FILES			=	srcs/extra/extra.c

LOG_FILES			=	./client_log.log \
						./server_log.log

SERV_OBJS			=	$(SERV_FILES:.c=.o)
CLIENT_OBJS			=	$(CLIENT_FILES:.c=.o)

EXTRA_SERV_OBJS		=	$(EXTRA_SERV_FILES:.c=.o)
EXTRA_CLIENT_OBJS	=	$(EXTRA_CLIENT_FILES:.c=.o)
EXTRA_OBJS			=	$(EXTRA_FILES:.c=.o)

%.o: %.c
					$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

NAME				= minitalk

$(NAME):		$(SERV_OBJS) $(CLIENT_OBJS) includes/minitalk.h Makefile
					make -C libft
					$(CC) -g $(SERV_OBJS) libft/libft.a -o server
					$(CC) -g $(CLIENT_OBJS) libft/libft.a -o client

extra:			$(EXTRA_OBJS) $(EXTRA_CLIENT_OBJS) $(EXTRA_SERV_OBJS) includes/minitalk_extra.h Makefile
					make -C libft
					rm -rf $(LOG_FILES)²
					$(CC) -g $(EXTRA_SERV_OBJS) $(EXTRA_OBJS) libft/libft.a -o server
					$(CC) -g $(EXTRA_CLIENT_OBJS) $(EXTRA_OBJS) libft/libft.a -o client
					


all:			$(NAME)

clean:
					make -C libft clean
					rm -f $(SERV_OBJS) $(CLIENT_OBJS) $(EXTRA_OBJS) $(EXTRA_CLIENT_OBJS) $(EXTRA_SERV_OBJS)

fclean:			clean
				make -C libft fclean
				rm -rf srcs/server.a srcs/client.a client server
				
re:				fclean all


.PHONY:			all clean fclean re
