/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:45:00 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/25 16:18:43 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field	**ft_change_map(t_field **map, int map_size, int new_map_size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_size)
		free((*map)->field[i]);
	free((*map)->field);
	(*map)->field = (char**)malloc(sizeof(char*) * new_map_size);
	i = -1;
	while (++i < new_map_size)
	{
		j = -1;
		(*map)->field[i] = (char*)malloc(sizeof(char) * (new_map_size + 1));
		(*map)->field[i][new_map_size] = '\0';
		while (++j < new_map_size)
			(*map)->field[i][j] = '.';
	}
	(*map)->size = new_map_size;
	return (map);
}
