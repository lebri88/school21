# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 17:11:13 by geliz             #+#    #+#              #
#    Updated: 2019/11/22 16:54:22 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
HEADERS = ./sources/
SRC_DIR = ./sources
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/checklines.c $(SRC_DIR)/cutstring.c $(SRC_DIR)/validate.c $(SRC_DIR)/createtetr.c $(SRC_DIR)/fill_list.c $(SRC_DIR)/fill_map.c $(SRC_DIR)/place_tetr.c $(SRC_DIR)/recursion.c
OBJ_DIR = .
LIB = ./libft/
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): LIB $(OBJ)
		gcc $(FLAGS) $(OBJ) -L$(LIB) -lft -o $(NAME)
LIB:
		make -C $(LIB)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		gcc -c $(FLAGS) -I$(HEADERS) $< -o $@

clean:
		make clean -C $(LIB)
		rm -rf $(OBJ)

fclean: clean
		make fclean -C $(LIB)
		rm -f $(NAME)

re: fclean all
