/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:31:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/24 17:36:08 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
#include <stdio.h>

int main(void)
{
	int fd = open("./test2.txt", 0);

	t_tetramina	*array;
	int			count;
	int			len;
	t_field		*map;
	//int			res;
	//int			pos;

	ft_check_valid_files(fd);//проверка на валидность файла
	fd = open("./test2.txt", O_RDONLY);
	count = ft_check_valid_figures(fd);//проверка на валидность фигур
	close(fd);
	fd = open("./test2.txt", 0);
	len = ft_square(count);//длина стороны квадрата
	printf("storona carti = %d\n", len);
	map = ft_create_field(len, count);//создает карту
	array = ft_coordinates(count);//создание массива на count  элементов
	ft_push_coordinates(fd, &array);//Заполнение координат
	close(fd);
	ft_entry_figure(array, map);
	ft_print_field(map, map->size);//Рисовка карты и её удаление
	free(array);
	return (0);
}
