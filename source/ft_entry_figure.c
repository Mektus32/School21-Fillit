/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:09:17 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/24 17:57:12 by ojessi           ###   ########.fr       */
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
	printf("map->size = %d\n", s);
//	printf("x1 = %d, y1 = %d, x2 = %d, y2 = %d, x3 = %d, y3 = %d, x4 = %d, y4 = %d\n",
//			0 + i, 0 + j, x1 + i, y1 + j, x2 + i, y2 + j, x3 + i, y3 + j);
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
		printf("check_entry worked\n");
		//ft_print_field(*map, (*map)->size);
		return (1);
	}
	printf("check_entry false\n");
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
	printf("clean worked\n");
}

int		ft_entry_figure(t_tetramina *arr, t_field *map)
{
	int				row;
	int				col;
	static	int		count = -1;
	int				s;

	s = map->size;
	row = -1;
	printf("first count = %d, map->count = %d\n", count + 2, map->count);
	if (++count == map->count)
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
	printf("count == %d\n", count);
	if (--count == -1)
	{
		printf("--count\n");
		s++;
		ft_free_field(&map, map->size);
		printf("ft_free_field worked\n");
		ft_create_field(s, map->count);
		printf("ft_create_field worked\n");
		ft_entry_figure(arr, map);
		//ft_print_field(map, s);
		printf("map++\n");
	}
	return (FALSE);
}
