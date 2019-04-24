/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:09:17 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/24 18:41:00 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
# define x1 arr[cur].num[1].x
# define y1 arr[cur].num[1].y
# define x2 arr[cur].num[2].x
# define y2 arr[cur].num[2].y
# define x3 arr[cur].num[3].x
# define y3 arr[cur].num[3].y
# define f (*map)->field

static	int		ft_check_entry_figure(t_tetramina *arr, t_field **map,
		int *params)
{
	int		i;
	int		j;
	int		cur;
	int		s;

	s = (*map)->size;
	i = params[0];
	j = params[1];
	cur = params[2];
	free(params);
	if (i + y1 >= 0 && i + y1 < s && i + y2 >= 0 && i + y2 < s && i + y3 >= 0 &&
			i + y3 < s && j + x1 >= 0 && j + x1 < s && j + x2 >= 0 && j + x2 < s
			&& j + x3 >= 0 && j + x3 < s && f[i][j] == '.' &&
			f[i + y1][j + x1] == '.' && f[i + y2][j + x2] == '.' &&
			f[i + y3][j + x3] == '.')
	{
		f[i][j] = arr[cur].character;
		f[i + y1][j + x1] = arr[cur].character;
		f[i + y2][j + x2] = arr[cur].character;
		f[i + y3][j + x3] = arr[cur].character;
		return (1);
	}
	return (0);
}

static	int		*ft_compact_params(int row, int col, int count)
{
	int		*params;

	params = (int*)malloc(sizeof(int) * 3);
	params[0] = row;
	params[1] = col;
	params[2] = count;
	return (params);
}

static	void	ft_clean_map(t_tetramina *arr, t_field **map,
		int *params)
{
	int		i;
	int		j;
	int		cur;

	i = params[0];
	j = params[1];
	cur = params[2];
	free(params);
	f[i][j] = '.';
	f[i + y1][j + x1] = '.';
	f[i + y2][j + x2] = '.';
	f[i + y3][j + x3] = '.';
}

int		ft_entry_figure(t_tetramina *arr, t_field *map)
{
	int				row;
	int				col;
	static	int		count = -1;
	int				s;

	s = map->size;
	row = -1;
	if (++count == map->count)
		return (TRUE);
	while (++row < s)
	{
		col = -1;
		while (++col < s)
			if (ft_check_entry_figure(arr, &map, ft_compact_params(row, col,
							count)))
			{
				if (ft_entry_figure(arr, map))
					return (TRUE);
				ft_clean_map(arr, &map, ft_compact_params(row, col, count));
			}
	}
	if (--count == -1)
	{
		s++;
		ft_free_field(&map, map->size);
		ft_create_field(s, map->count);
		ft_entry_figure(arr, map);
	}
	return (FALSE);
}
