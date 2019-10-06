# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 14:02:59 by geliz             #+#    #+#              #
#    Updated: 2019/09/29 16:58:14 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GNL 
FLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line.c
OFILES = main.o get_next_line.o

all: $(NAME)

$(NAME): $(OFILES)
./%o:./%.c
		gcc $(FLAGS) -L. -lft $< -o $@

clean:
		rm -rf $(OFILES)

fclean:
		rm -f $(NAME)

re: fclean all
