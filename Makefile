# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/06/18 15:11:29 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS				=	-g -Wall -Werror -Wextra

CC					=	cc

CLIENT_FILES		=	./srcs/client.c \
						./srcs/ft_send.c
SERV_FILES			=	./srcs/server.c
LIST_FILES			=	./srcs/list/ft_lstnew.c \
						./srcs/list/ft_lstadd_back.c \
						./srcs/list/ft_lstclear.c \
						./srcs/list/ft_lstprint.c


EXTRA_SERV_FILES	=	./srcs/extra/server_extra.c
EXTRA_CLIENT_FILES	=	./srcs/extra/client_extra.c \
						./srcs/extra/ft_send_extra.c
EXTRA_FILES			=	./srcs/extra/extra.c \
						./srcs/extra/extra_colour.c \
						./srcs/extra/ft_rainbow_effect.c \
						./srcs/extra/log.c \
						./srcs/extra/ft_lstprint_extra.c \
						./srcs/extra/help.c \
						./srcs/extra/sig_char.c \
						./srcs/extra/init.c

LOG_FILES			=	./client_log.log \
						./server_log.log

SERV_OBJS			=	$(SERV_FILES:.c=.o)
CLIENT_OBJS			=	$(CLIENT_FILES:.c=.o)
LIST_OBJS			=	$(LIST_FILES:.c=.o)

EXTRA_SERV_OBJS		=	$(EXTRA_SERV_FILES:.c=.o)
EXTRA_CLIENT_OBJS	=	$(EXTRA_CLIENT_FILES:.c=.o)
EXTRA_OBJS			=	$(EXTRA_FILES:.c=.o)

GREEN				=	\e[0;32m
NC					=	\e[0m

LIBFT				= libft/libft.a

%.o:				%.c Makefile includes/minitalk.h includes/minitalk_extra.h
					$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

NAME				= minitalk


$(NAME):		libft server client includes/minitalk.h Makefile
					@echo "$(GREEN)All files compiled succesfully :D$(NC)"

extra:			libft server_extra client_extra includes/minitalk_extra.h Makefile
					@echo "$(GREEN)All files compiled succesfully :D$(NC)"

$(LIBFT):
				@make -s -C libft

server:			$(SERV_OBJS) $(LIST_OBJS) $(LIBFT) includes/minitalk.h Makefile
					$(CC) -g $(SERV_OBJS) $(LIST_OBJS) $(LIBFT) -o server

client:			$(CLIENT_OBJS) $(LIST_OBJS) $(LIBFT) includes/minitalk.h Makefile
					$(CC) -g $(CLIENT_OBJS) $(LIST_OBJS) $(LIBFT) -o client

server_extra:	$(EXTRA_SERV_OBJS) $(EXTRA_OBJS) $(LIST_OBJS) $(LIBFT) includes/minitalk_extra.h Makefile
					$(CC) -g $(EXTRA_SERV_OBJS) $(EXTRA_OBJS) $(LIST_OBJS) $(LIBFT) -o server_extra

client_extra:	$(EXTRA_CLIENT_OBJS) $(EXTRA_OBJS) $(LIST_OBJS) $(LIBFT) includes/minitalk_extra.h Makefile
					$(CC) -g $(EXTRA_CLIENT_OBJS) $(EXTRA_OBJS) $(LIST_OBJS) $(LIBFT) -o client_extra

all:			$(NAME)

clean:
				@make -s -C libft clean
				@rm -f $(SERV_OBJS) $(CLIENT_OBJS) $(LIST_OBJS) $(EXTRA_OBJS) $(EXTRA_CLIENT_OBJS) $(EXTRA_SERV_OBJS)
				@echo "$(GREEN)All object files deleted succesfully :D$(NC)"

fclean:			clean
				@make -s -C libft fclean
				@rm -rf srcs/server.a srcs/client.a client server client_extra server_extra
				@echo "$(GREEN)All library and programm files deleted succesfully :D$(NC)"
				
re:				fclean all


.PHONY:			all clean fclean re
