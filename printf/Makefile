# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <geliz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 17:11:13 by geliz             #+#    #+#              #
#    Updated: 2020/01/11 17:37:32 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEADERS = ./includes/
SRC_DIR = ./sources
SRC = $(SRC_DIR)/ft_printf_hub.c $(SRC_DIR)/check_content.c $(SRC_DIR)/readkeys.c \
	  $(SRC_DIR)/type_char.c $(SRC_DIR)/type_string.c $(SRC_DIR)/type_percent.c $(SRC_DIR)/type_ptr.c \
	  $(SRC_DIR)/type_int.c $(SRC_DIR)/type_int_convert_to_str.c $(SRC_DIR)/type_int_width_and_space.c \
	  $(SRC_DIR)/type_int_octotorp_base.c $(SRC_DIR)/type_int_hexadec.c \
	  $(SRC_DIR)/ft_ll_itoa.c $(SRC_DIR)/ft_unsigned_ll_itoa_base.c $(SRC_DIR)/ft_unsigned_ll_itoa_base_hub.c \
	  $(SRC_DIR)/type_float.c $(SRC_DIR)/type_float_mant_count.c $(SRC_DIR)/type_float_neg_powers.c \
	  $(SRC_DIR)/type_float_check_parts.c $(SRC_DIR)/type_float_apply_info.c $(SRC_DIR)/type_float_apply_width.c \
	  $(SRC_DIR)/type_float_apply_prec_zero.c $(SRC_DIR)/type_float_apply_prec_not_zero.c \
	  $(SRC_DIR)/type_float_apply_plus_space.c $(SRC_DIR)/type_float_keys_to_spec.c $(SRC_DIR)/type_float_long.c \
	  $(SRC_DIR)/ft_from_lib_newstrings.c $(SRC_DIR)/ft_from_lib_fill_and_del_str.c $(SRC_DIR)/ft_from_lib_atoi_toupp.c \
	  $(SRC_DIR)/ft_type_binary.c $(SRC_DIR)/ft_strjoin_spec.c $(SRC_DIR)/ft_printf_bonus_hub.c $(SRC_DIR)/bonus_colors.c \
	  $(SRC_DIR)/bonus_color_add_colorcode.c
OBJ_DIR = ./sources
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@gcc -c $(FLAGS) -I$(HEADERS) $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
