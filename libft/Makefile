# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 13:08:06 by brehaili          #+#    #+#              #
#    Updated: 2014/02/27 21:51:55 by gleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strsplit.c ft_ptrlen.c ft_bad_malloc.c\
ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_pow.c ft_nb_digit.c \
ft_bad_open.c ft_exit.c ft_strsplit_clr.c

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	ar rc $(NAME) $^
	ranlib $(NAME)
	@echo "\033[1;32;m[Libft successfully created] \t\t\t\033[0m"

%.o: %.c
	@gcc -c $^ -o $@ -Wall -Wextra -Werror -g -O3

clean:
	rm -rf $(SRC:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all
