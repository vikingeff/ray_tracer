# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brehaili <brehaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/13 19:23:12 by brehaili          #+#    #+#              #
#    Updated: 2014/02/13 19:23:12 by brehaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
SRC = rtv1.c mlx_add.c init.c parse_function.c inter_function.c list.c \
		get_next_line.c vector.c vector2.c color.c rtv12.c hook.c
CCFLAG = #-Wall -Wextra -Werror
FLAG = -Llibft -lft -lmlx -L/usr/X11/lib -lX11 -lXext 

all: libft.a $(NAME)

$(NAME): $(SRC:.c=.o)
	gcc -o $(NAME) $(SRC:.c=.o) $(FLAG) $(CCFLAG) -g -lm

libft.a:
	make -C libft

%.o: %.c
	gcc -g -c $^ -o $@ $(CCFLAG) -g

clean:
	rm -rf $(SRC:.c=.o)

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
