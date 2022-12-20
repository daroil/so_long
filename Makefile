# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 15:26:49 by dhendzel          #+#    #+#              #
#    Updated: 2022/12/20 15:47:23 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRCS = 			main.c initialise.c movement.c movement_2.c make_map.c \
				map_check.c map_check_2.c game_checks.c
BONUS_SRCS = 	main_bonus.c movement_bonus.c movement_2_bonus.c make_map_bonus.c \
				map_check_bonus.c map_check_2_bonus.c game_checks_bonus.c \
				initialise_bonus.c enemy_handle_bonus.c enemy_movement_bonus.c \
				enemy_movement_bonus_2.c delete_bonus.c

BONUS_NAME =  so_long_bonus
NAME =  so_long
OBJ	= $(SRCS:.c=.o)
BONUS_OBJ	= $(BONUS_SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf
GNL	:= ./lib/gnl

all: libmlx libft printf gnl $(NAME)

bonus: libmlx libft printf gnl $(BONUS_NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFT)

printf:
	@$(MAKE) -C $(PRINTF)

gnl:
	@$(MAKE) -C $(GNL)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBMLX)/libmlx42.a $(PRINTF)/libftprintf.a $(LIBFT)/libft.a $(GNL)/gnl.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(LIBMLX)/libmlx42.a $(PRINTF)/libftprintf.a $(LIBFT)/libft.a $(GNL)/gnl.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(BONUS_NAME)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(PRINTF) clean
	@$(MAKE) -C $(GNL) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(PRINTF) fclean
	@$(MAKE) -C $(GNL) fclean
	
clean_bonus:
	rm -f $(BONUS_OBJ)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(PRINTF) clean
	@$(MAKE) -C $(GNL) clean

fclean_bonus: clean_bonus
	rm -f $(BONUS_NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(PRINTF) fclean
	@$(MAKE) -C $(GNL) fclean

re: fclean all

norm:
	norminette $(SRCS) so_long.h
	norminette $(BONUS_SRCS) so_long_bonus.h
	@$(MAKE) -C $(LIBFT) norm
	@$(MAKE) -C $(PRINTF) norm
	@$(MAKE) -C $(GNL) norm
	
install:
	brew update
	brew install glfw

.PHONY: all clean fclean re printf libft libmlx gnl bonus fclean_bonus clean_bonus norm install