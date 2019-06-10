# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 14:33:23 by ojessi            #+#    #+#              #
#    Updated: 2019/04/27 16:58:57 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = source/ft_change_map.c \
	  source/ft_check_valid_figures.c \
  	  source/ft_check_valid_files.c \
	  source/ft_coordinates.c \
	  source/ft_create_field.c \
	  source/ft_entry_figure.c \
	  source/ft_free_field.c \
	  source/ft_print_error.c \
	  source/ft_print_field.c \
	  source/ft_push_coordinates.c \
	  source/ft_square.c \
	  source/ft_usage.c \
	  source/get_next_line.c \
	  source/main.c
OBJ = source/*.o
FLAGS = -Wextra -Wall -Werror
HEAD = headers/
LIBFT = libft/

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) $(SRC) -I $(HEAD) -o $(NAME) -L. libft/libft.a

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
