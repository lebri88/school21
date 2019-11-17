# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 17:11:13 by geliz             #+#    #+#              #
#    Updated: 2019/11/17 16:07:20 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEADERS = ./includes/
SRC_DIR = ./sources
SRC = $(SRC_DIR)/hub.c $(SRC_DIR)/checkcont.c $(SRC_DIR)/readkeys.c
OBJ_DIR = ./obj
LIB = ./libft/
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): LIB $(OBJ)
		ar rc $(NAME) $(OBJ)
LIB:
		make -C $(LIB)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(@D)
		gcc -c $(FLAGS) -I$(HEADERS) $< -o $@

clean:
		make clean -C $(LIB)
		rm -rf $(OBJ)
		rm -rf $(OBJ_DIR)

fclean: clean
		make fclean -C $(LIB)
		rm -f $(NAME)

re: fclean all
