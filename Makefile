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
C_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
C_SRC =	checker/applay_instructions.c\
		checker/check_instructions.c\
		checker/doubly_linked_list.c\
		checker/main.c

C_OBJ = $(C_SRC:.c=.o)

all: $(C_NAME)

$(C_NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(C_SRC)
		@$(CC) $(CFLAGS) $(C_NAME) $(C_OBJ) $(LIB)
		
clean:
		@rm -f $(OBJ)
		
fclean:
		@make clean
		@rm -f $(NAME)		
re:
		@make fclean
		@make all
		@ar rc $(NAME) $(OBJ)
