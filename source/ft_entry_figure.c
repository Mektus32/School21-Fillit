/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:09:17 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/25 16:22:07 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define X1 arr[cur].num[1].x
#define Y1 arr[cur].num[1].y
#define X2 arr[cur].num[2].x
#define Y2 arr[cur].num[2].y
#define X3 arr[cur].num[3].x
#define Y3 arr[cur].num[3].y
#define F (*map)->field

static	int			ft_check_entry_figure(t_tetramina *arr, t_field **map,
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
	if (i + Y1 >= 0 && i + Y1 < s && i + Y2 >= 0 && i + Y2 < s && i + Y3 >= 0 &&
			i + Y3 < s && j + X1 >= 0 && j + X1 < s && j + X2 >= 0 && j + X2 < s
			&& j + X3 >= 0 && j + X3 < s && F[i][j] == '.' &&
			F[i + Y1][j + X1] == '.' && F[i + Y2][j + X2] == '.' &&
			F[i + Y3][j + X3] == '.')
	{
		F[i][j] = arr[cur].character;
		F[i + Y1][j + X1] = arr[cur].character;
		F[i + Y2][j + X2] = arr[cur].character;
		F[i + Y3][j + X3] = arr[cur].character;
		return (1);
	}
	return (0);
}

static	int			*ft_compact_params(int row, int col, int count)
{
	int		*params;

	params = (int*)malloc(sizeof(int) * 3);
	params[0] = row;
	params[1] = col;
	params[2] = count;
	return (params);
}

static	void		ft_clean_map(t_tetramina *arr, t_field **map,
		int *params)
{
	int		i;
	int		j;
	int		cur;

	i = params[0];
	j = params[1];
	cur = params[2];
	free(params);
	F[i][j] = '.';
	F[i + Y1][j + X1] = '.';
	F[i + Y2][j + X2] = '.';
	F[i + Y3][j + X3] = '.';
}

int					ft_entry_figure(t_tetramina *arr, t_field **map)
{
	int				row;
	int				col;
	static	int		count = -1;

	row = -1;
	if (++count == (*map)->count)
		return (TRUE);
	while (++row < (*map)->size)
	{
		col = -1;
		while (++col < (*map)->size)
			if (ft_check_entry_figure(arr, map, ft_compact_params(row, col,
							count)))
			{
				if (ft_entry_figure(arr, map))
					return (TRUE);
				ft_clean_map(arr, map, ft_compact_params(row, col, count));
			}
	}
	if (--count == -1)
		ft_entry_figure(arr, ft_change_map(map, (*map)->size,
					(*map)->size + 1));
	return (FALSE);
}
