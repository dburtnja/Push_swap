# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/03/07 18:41:05 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

C_NAME = checker
P_NAME = push_swap
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
C_SRC =	checker_dir/applay_instructions.c\
		checker_dir/check_instructions.c\
		checker_dir/doubly_linked_list.c\
		checker_dir/main.c

P_SRC = push_swap_dir/bubble_sort.c\
		push_swap_dir/find_sort_algorithm.c\
		push_swap_dir/check_if_sort.c\
		checker_dir/doubly_linked_list.c\
		push_swap_dir/main.c\
		push_swap_dir/ps_applay_instructions.c\
		push_swap_dir/sort_b_part.c\
		push_swap_dir/sort_a_part.c\
		push_swap_dir/move_to_b.c

C_OBJ = $(C_SRC:.c=.o)
P_OBJ = $(P_SRC:.c=.o)

all:	$(LIB) $(C_NAME) $(P_NAME)

$(LIB):
		make -C ./libft

$(C_NAME): $(C_OBJ) 
		@$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

$(P_NAME): $(P_OBJ) 
		@$(CC) $(CFLAGS) $(P_OBJ) -o $(P_NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

clean_checker: 
		@rm -f $(C_OBJ)	
clean_push_swap: 
		@rm -f $(P_OBJ)
clean:
		@make clean -C ./libft
		@make clean_checker
		@make clean_push_swap

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(C_NAME)
		@rm -f $(P_NAME)
re:
		@make fclean
		@make all
