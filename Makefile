# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/13 19:23:12 by brehaili          #+#    #+#              #
#    Updated: 2014/03/01 00:28:54 by gleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
SRC = rtv1.c mlx_add.c init.c parse_function.c inter_function.c list.c \
		get_next_line.c vector.c vector2.c color.c rtv12.c hook.c
CCFLAG = -Wall -Wextra -Werror -g -O3
FLAG = -Llibft -lft -lmlx -lm -L/usr/X11/lib -lX11 -lXext 

all: libft.a $(NAME)

$(NAME): $(SRC:.c=.o)
	gcc -o $(NAME) $(SRC:.c=.o) $(FLAG) $(CCFLAG)

libft.a:
	make -C libft

%.o: %.c
	@gcc -g -c $^ -o $@ $(CCFLAG)

clean:
	rm -rf $(SRC:.c=.o)

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
