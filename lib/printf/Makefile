# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:53:59 by dhendzel          #+#    #+#              #
#    Updated: 2022/12/17 13:07:53 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
SRCS =  ft_putchar.c ft_putstr.c \
		ft_putnbr.c ft_printf.c ft_print_hexa.c\
		ft_print_pointer.c ft_put_unsigned_nbr.c

NAME = libftprintf.a 
OBJ	= $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
norm:
	norminette $(SRCS)

re: fclean all

.PHONY: all clean fclean re norm