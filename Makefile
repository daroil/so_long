# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 15:26:49 by dhendzel          #+#    #+#              #
#    Updated: 2022/12/17 12:52:15 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = main.c get_next_line_utils.c get_next_line.c movement.c movement_2.c make_map.c map_check.c map_check_2.c game_checks.c

NAME =  so_long
OBJ	= $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf

all: libmlx libft printf $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

printf:
	@$(MAKE) -C $(PRINTF)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBMLX)/libmlx42.a $(PRINTF)/libftprintf.a $(LIBFT)/libft.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(PRINTF) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(PRINTF) fclean

re: fclean all

norm:
	norminette $(SRCS)
	
install:
	brew update
	brew install glfw

.PHONY: all clean fclean re norm install printf libft libmlx