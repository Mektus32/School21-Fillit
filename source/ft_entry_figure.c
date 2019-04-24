/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:09:17 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/24 16:21:43 by ojessi           ###   ########.fr       */
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
	if (i + x1 > 0 && i + x1 < s && i + x2 > 0 && i + x2 < s && i + x3 > 0 &&
			i + x3 < s && j + y1 > 0 && j + y1 < s && j + y2 > 0 && j + y2 < s
			&& j + y3 > 0 && j + y3 < s && f[i][j] == '.' &&
			f[i + x1][j + y1] == '.' && f[i + x2][j + y2] == '.' &&
			f[i + x3][j + y3] == '.')
	{
		f[i][j] = arr->character;
		f[i + x1][j + y1] = arr->character;
		f[i + x2][j + y2] = arr->character;
		f[i + x3][j + y3] = arr->character;
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
	f[i + x1][j + y1] = '.';
	f[i + x2][j + y2] = '.';
	f[i + x3][j + y3] = '.';
}

int		ft_entry_figure(t_tetramina *arr, t_field *map)
{
	int				row;
	int				col;
	static	int		count = -1;
	int				s;
	int				len;

	s = map->size;
	row = -1;
				printf("check0\n");
	if (++count > map->count)
		return (TRUE);
	while (++row < s)
	{
		col = -1;
				printf("check1\n");
		while (++col < s)
			if (ft_check_entry_figure(arr, &map, ft_compact_params(row, col,
							count)))
			{
				if (ft_entry_figure(arr, map))
					return (TRUE);
				printf("check2\n");
				ft_clean_map(arr, &map, ft_compact_params(row, col, count));
			}
	}
	if (--count == -1)
	{
		len = map->size + 1;
		ft_free_field(&map, map->size);
		ft_create_field(len, len);
		ft_entry_figure(arr, map);
	}
	return (FALSE);
}
