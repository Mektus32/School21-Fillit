# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 14:33:23 by ojessi            #+#    #+#              #
#    Updated: 2019/04/24 20:49:30 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = source/*.c \
	  libft/libft.a
OBJ = source/*.o
FLAGS = -Wextra -Wall -Werror -g
HEAD = headers/
LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) $(SRC) -I $(HEAD) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: clean all
