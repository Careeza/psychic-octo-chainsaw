# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 15:24:29 by ochaar            #+#    #+#              #
#    Updated: 2018/11/23 16:26:15 by ochaar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ft_verif.c main.c ft_algo.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -Llibft -lft -I libft

clean:
	/bin/rm -rf $(OBJ)
	@make -C ./libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all
