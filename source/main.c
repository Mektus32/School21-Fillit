/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:31:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/24 21:52:18 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetramina	*array;
	int			count;
	int			len;
	t_field		*map;
	int			fd;

	if (argc != 2)
		exit(0);
	argc = 2;
	fd = open(argv[1], O_RDONLY);
	ft_check_valid_files(fd);
	fd = open(argv[1], O_RDONLY);
	count = ft_check_valid_figures(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	len = ft_square(count);
	map = ft_create_field(len, count);
	array = ft_coordinates(count);
	ft_push_coordinates(fd, &array);
	close(fd);
	ft_entry_figure(array, map);
	free(map);
	free(array);
	return (0);
}
