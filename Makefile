# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 10:35:08 by hrothery          #+#    #+#              #
#    Updated: 2022/01/05 11:08:26 by hrothery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC =	ft_printf.c \
		ft_hex.c \
		print_char.c \
		ft_itoa.c \
		ft_strlen.c \
		itoa_unsigned.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all = $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean $(all)
