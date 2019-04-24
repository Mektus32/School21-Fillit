/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:31:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/24 18:56:34 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int main(int argc, char **argv)
{
	t_tetramina	*array;
	int			count;
	int			len;
	t_field		*map;
	int			fd;

	if (argc != 2)
		exit(0);
	argc = 2;
	//	ft_putstr("usage: ./fillit source_file\n");
	fd = open(argv[1], O_RDONLY);
	ft_check_valid_files(fd);//проверка на валидность файла
	fd = open(argv[1], O_RDONLY);
	count = ft_check_valid_figures(fd);//проверка на валидность фигур
	close(fd);
	fd = open(argv[1], O_RDONLY);
	len = ft_square(count);//длина стороны квадрата
	map = ft_create_field(len, count);//создает карту
	array = ft_coordinates(count);//создание массива на count  элементов
	ft_push_coordinates(fd, &array);//Заполнение координат
	close(fd);
	ft_entry_figure(array, map);
	ft_print_field(map, map->size);//Рисовка карты и её удаление
	free(array);
	return (0);
}
