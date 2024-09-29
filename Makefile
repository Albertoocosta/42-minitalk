# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 19:31:40 by cda-fons          #+#    #+#              #
#    Updated: 2024/09/29 12:01:32 by cda-fons         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
NAMEC = client
NAMES = server
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRCS = client.c 
SRSS = server.c

all:	${NAMEC} ${NAMES}

${LIBFT}:
	@make -C Libft
${PRINTF}:
	@make -C Printf
${NAMEC}: ${LIBFT} ${PRINTF}
	@${CC} ${SRCS} ${LIBFT} ${PRINTF} ${FLAGS} -o ${NAMEC}
${NAMES}: ${LIBFT} ${PRINTF}
	${CC} ${SRSS} ${LIBFT} ${PRINTF} ${FLAGS} -o ${NAMES}
clean:
	@rm ${NAMEC}
	@rm ${NAMES}
	@echo ALL CLEAR
re: clean all