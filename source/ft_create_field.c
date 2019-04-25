/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:55:41 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/25 15:16:50 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field	*ft_create_field(int map_size, int count_figure)
{
	int		i;
	int		j;
	t_field	*map;

	i = -1;
	map = (t_field*)malloc(sizeof(t_field));
	map->field = (char**)malloc(sizeof(char*) * map_size);
	map->size = map_size;
	while (++i < map_size)
	{
		j = -1;
		map->field[i] = (char*)malloc(sizeof(char) * (map_size + 1));
		map->field[i][map_size] = '\0';
		while (++j < map_size)
			map->field[i][j] = '.';
	}
	map->count = count_figure;
	return (map);
}
