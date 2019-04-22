/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:09:17 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/22 20:30:58 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
# define x1 arr[cur].num[1].x
# define y1 arr[cur].num[1].y
# define x2 arr[cur].num[2].x
# define y2 arr[cur].num[2].y
# define x3 arr[cur].num[3].x
# define y3 arr[cur].num[3].y
# define s map->size

int		ft_entry_figure(t_tetramina *arr, t_field *map)
{
	int				row;
	int				col;
	static	int		count = 0;

	if (count > map->count)
		return (TRUE);
	while (++row < s)
	{
		col = -1;
		while (++col < s)
			if (ft_check_entry_figure())
			{
				ft_tmp_fill_map();
				if (ft_entry_figure())
					return (TRUE);
				ft_clean_map();
			}
	}
	return (FALSE);
}
