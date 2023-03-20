# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:10:12 by llevasse          #+#    #+#              #
#    Updated: 2023/03/20 13:06:57 by llevasse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			= -Wall -Werror -Wextra

FILES			=	

OBJS			=	${FILES:.c=.o}

%.o: %.c 
					gcc ${FLAGS} -I includes -c $< -o ${<:.c=.o} -lmlx -lXext -lX11 -lm
					
${NAME}:		${OBJS} includes/fdf.h Makefile
					make -C libft 
					ar rcs ${NAME} libft/libft.a ${OBJS}
					gcc ${NAME} -o ${EXECUTABLE}

all:			${NAME}

clean:
					make -C libft clean
					rm -f ${OBJS}

fclean:			clean
					rm -f ${NAME} ${EXECUTABLE}

re:				fclean all


.PHONY:			all clean fclean re
