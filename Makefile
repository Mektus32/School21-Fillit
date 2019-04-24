# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 14:33:23 by ojessi            #+#    #+#              #
#    Updated: 2019/04/24 18:54:33 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = source/*.c libft/libft.a
FLAGS = -Wextra -Wall -Werror
HEAD = headers/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -I $(HEAD) -o $(NAME)
	./$(NAME)

clean:
	/bin/rm -f $(NAME)
fclean:
	/bin/rm -f $(NAME)

re: clean all
