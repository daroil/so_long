# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 15:18:30 by dhendzel          #+#    #+#              #
#    Updated: 2022/12/17 13:08:13 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = ft_isalpha.c ft_strlen.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c 
NAME = libft.a 
OBJ	= $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)
	
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# norm:
# 	norminette $(SRCS) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean clean all BONUS
