# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 22:56:38 by mfallahi          #+#    #+#              #
#    Updated: 2022/03/14 22:12:04 by mfallahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = So_long.h
NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit
CFILES =  gnl.c\
		init.c\
		main.c\
		parsing.c\
		play.c\
		rendering.c\

OFILES = $(CFILES:.c=.o)

$(NAME) : $(OFILES) $(INC) 
	$(CC) $(CFLAGS) $(MLX)  $(CFILES) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OFILES)
fclean : clean
	rm -rf $(NAME)

re : fclean all