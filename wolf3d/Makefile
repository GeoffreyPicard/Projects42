# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gepicard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 15:49:48 by gepicard          #+#    #+#              #
#    Updated: 2016/12/11 13:02:02 by gepicard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Wall -Wextra -Werror

NAME=wolf3d

SRC=    main.c\
				ft_parse.c\
				ft_ray.c\
				ft_img.c\
				ft_env.c\

OBJ=$(SRC_POS:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C mlx/
	@gcc ./libft/libft.a ./mlx/libmlx.a -lmlx -framework OpenGL -framework Appkit $(FLAGS) $(OBJ) -I includes -o $(NAME)

%.o: %.c
	@gcc -o $@ -c $(FLAGS) $< -I./libft/includes -I./mlx -I includes

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@make -C mlx/ clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@make -C mlx/ clean

re: fclean all

.PHONY: clean
	@rm -rf $(OBJ)
