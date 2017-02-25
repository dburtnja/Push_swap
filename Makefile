# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2016/12/09 20:49:04 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libraries/libget_nex_line.a
PREFIX = checker_dir/
C_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_SRC =	applay_instructions.c\
		check_instructions.c\
		doubly_linked_list.c\
		main.c

C_OBJ = $(C_SRC:.c=.o)

C_SRC = $(PREFIX)$(C_SRC)

all: $(C_NAME)

$(C_NAME):
		@$(CC) -c $(CFLAGS) $(PREFIX)$(C_SRC)
		@$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJ) $(LIB)
		
clean:
		@rm -f $(OBJ)
		
fclean:
		@make clean
		@rm -f $(NAME)		
re:
		@make fclean
		@make all
		@ar rc $(NAME) $(OBJ)
