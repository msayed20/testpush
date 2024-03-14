# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:37:34 by suhelal           #+#    #+#              #
#    Updated: 2024/03/13 21:54:00 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES 	   = push_swap.c error_free.c sorting_three.c sorting.c conversion.c instructions_rrr.c instructions_ss.c instructions_rr.c check_argument.c \
join_arg.c push_swap_utils.c find_max_min.c find_new_num_a.c move_stack_a.c sort_stack_a.c split_arg.c move_b_num.c find_cheapest_move.c \
print_list.c sort_multi.c sorting_four.c instructions_pa_pb.c conv_num.c \

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

NAME	= push_swap

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: clean $(NAME)
