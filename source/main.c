/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:31:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/25 16:22:35 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetramina	*array;
	int			count_figure;
	int			map_size;
	t_field		*map;
	int			fd;

	if (argc != 2)
		ft_usage();
	argc = 2;
	fd = open(argv[1], O_RDONLY);
	ft_check_valid_files(fd);
	fd = open(argv[1], O_RDONLY);
	count_figure = ft_check_valid_figures(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_size = ft_square(count_figure);
	map = ft_create_field(map_size, count_figure);
	array = ft_coordinates(count_figure);
	ft_push_coordinates(fd, &array);
	close(fd);
	ft_entry_figure(array, &map);
	ft_print_field(map, map->size);
	ft_free_field(&map, map->size);
	free(array);
	return (0);
}
