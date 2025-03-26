# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opopov <opopov@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 13:22:01 by opopov            #+#    #+#              #
#    Updated: 2025/03/26 13:06:22 by opopov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := push_swap
SRC_DIR := srcs
SRC     := commands_push.c commands_reverse_rotate.c \
			commands_rotate.c commands_swap.c \
			operations_for_a.c operations_for_b.c \
			push_swap_utils.c push_swap.c \
			rotation_operations.c sorting.c \
			utils_for_utils.c

OBJ     := $(SRC:.c=.o)
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

LIBFT_DIR	:= Libft
LIBFT		:= $(LIBFT_DIR)/libft.a

PRINTF_DIR	:= ft_printf
PRINTF		:= $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
