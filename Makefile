# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 15:26:49 by dhendzel          #+#    #+#              #
#    Updated: 2022/12/05 17:15:37 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = main.c get_next_line_utils.c get_next_line.c

NAME =  game
OBJ	= $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) libmlx42.a libftprintf.a libft.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 