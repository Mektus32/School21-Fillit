/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:31:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/21 21:04:10 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"
#include <stdio.h>

int main(void)
{
	int fd = open("./test2.txt", 0);

	tetramina	*array;
	int			count;
	int			len;
	field		*map;
	int			res;
	int			pos;

	ft_check_valid_files(fd);//проверка на валидность файла
	fd = open("./test2.txt", O_RDONLY);
	count = ft_check_valid_figures(fd);//проверка на валидность фигур
	close(fd);
	//array = ft_create_arr(count);//создание массива на count элементов(del)
	fd = open("./test2.txt", 0);
	len = ft_square(count);//длина стороны квадрата
	map = ft_create_field(len);//создает картуш
	array = ft_coordinates(count);//создание массива на count  элементов
	ft_push_coordinates(fd, &array);//Заполнение координат
	close(fd);
	res = 0;
	while (res < count)
	{
		pos = 0;
		while (pos < 4)
		{
			printf("x = %d     " ,array[res].num_of_tetr.num[pos].x);
			printf("y = %d\n",array[res].num_of_tetr.num[pos].y);
			pos++;
		}
		res++;
	}
	free(array);
	return (0);
}
