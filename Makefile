# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 08:51:56 by murachid          #+#    #+#              #
#    Updated: 2021/02/22 08:51:58 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d.a

SRC = *.c

OBJECT = *.o

all: $(NAME)

$(NAME):

	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)
	gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit *.c get_next_line/*.c libft/*.c  -o cub3D
	rm -f $(OBJECT)

clean:
	rm -f $(OBJECT) 
fclean: clean
	rm -f $(NAME)
	rm -f cub3D
re: fclean all