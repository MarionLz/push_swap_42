# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 10:37:47 by malauzie          #+#    #+#              #
#    Updated: 2023/12/19 18:03:23 by malauzie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include

SRC = src/instructions/push.c src/instructions/reverse_rotate.c \
src/instructions/rotate.c src/instructions/swap.c \
src/push_swap/check_and_convert_input.c src/push_swap/handle_errors.c \
src/push_swap/init_stack.c src/push_swap/move_a_to_b.c \
src/push_swap/move_b_to_a.c src/push_swap/push_swap.c \
src/push_swap/sort_stack.c src/utils/chained_list.c src/utils/ft_split.c \
src/utils/strings.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all