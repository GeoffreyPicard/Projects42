# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gepicard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:35:27 by gepicard          #+#    #+#              #
#    Updated: 2016/11/03 18:08:32 by gepicard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRC= srcs/ft_putchar.c\
	srcs/ft_putstr.c\
	srcs/ft_strcmp.c\
	srcs/ft_strlen.c\
	srcs/ft_swap.c

OBJ= ft_putchar.o\
	ft_putstr.o\
	ft_strcmp.o\
	ft_strlen.o\
	ft_swap.o

$(NAME):
	gcc -c $(SRC)
	ar rc libft.a $(OBJ)
	ranlib libft.a

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
