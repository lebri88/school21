# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 17:11:13 by geliz             #+#    #+#              #
#    Updated: 2019/09/27 14:22:59 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
HEADERS = ./includes/libft.h ./includes/fillit.h
SRC = ./sources/*.c
LIB = ./libft/libft.a
OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
./%o:./%.c
		gcc -c $(FLAGS) -Ilibft.h $< -o $@

clean:
		rm -rf $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all
