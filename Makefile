# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/02/25 19:35:54 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

C_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_SRC =	checker_dir/applay_instructions.c\
		checker_dir/check_instructions.c\
		checker_dir/doubly_linked_list.c\
		checker_dir/main.c

C_OBJ = $(C_SRC:.c=.o)

all:	$(C_NAME)

$(C_NAME): $(C_OBJ)
		make -C ./libft
		@$(CC) $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

clean:
		@make clean -C ./libft
		@rm -f $(C_OBJ)	

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(C_NAME)		
re:
		@make fclean
		@make all
