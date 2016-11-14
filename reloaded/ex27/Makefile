# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gepicard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:35:27 by gepicard          #+#    #+#              #
#    Updated: 2016/11/03 11:40:45 by gepicard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Werror -Wextra

NAME= ft_display_file

SRC= srcs/main.c

OBJ= main.o

$(NAME):
	gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean
	all
