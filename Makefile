# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 15:54:47 by ldoidy            #+#    #+#              #
#    Updated: 2025/01/13 17:30:14 by ldoidy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


SRCS = main.c \
        $(addprefix stack_functions/, stack_utils.c ft_free_stack.c) \
        $(addprefix indexing_functions/, indexing_utils.c) \
        $(addprefix moves/, swap.c rotate.c reverse_rotate.c push.c) \
        $(addprefix 3_numbers/, sort_three_numbers.c) \
        $(addprefix 5_numbers/, sort_five_numbers.c) \
        $(addprefix big_numbers/, big_sort.c find_sequence.c check_max_value.c do_moves.c find_best_push.c prepare_stack_a.c) \
        $(addprefix tools/, ft_atoi.c ft_split.c function_utils.c) \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
