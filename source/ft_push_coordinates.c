/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:18:54 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/22 17:59:38 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ft_delta_x_y(t_tetramina **pointer, int column, int row,
		int count)
{
		(*pointer)[count].num[0].x = column;
		(*pointer)[count].num[0].y = row;
}

static	void	ft_push_struct_coor(char **place, int count,
		t_tetramina **pointer)
{
	int		column;
	int 	row;
	int		num;

	num = -1;
	row = -1;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
			if (place[row][column] == '#')
			{
				if (++num == 0)
					ft_delta_x_y(pointer, column, row, count);
				else
				{	
					(*pointer)[count].num[num].x = column -
						(*pointer)[count].num[0].x;
					(*pointer)[count].num[num].y = row -
						(*pointer)[count].num[0].y;
				}
			}
	}
	(*pointer)[count].num[0].x = 0;
	(*pointer)[count].num[0].y = 0;
}

static	char	**ft_create_place(void)
{
	char		**place;
	int			i;

	place = (char**)malloc(sizeof(char*) * 4);
	i = -1;
	while (++i < 4)
	{
		place[i] = (char*)malloc(sizeof(char) * 5);
		place[i][4] = '\0';
	}
	return (place);
}

static	void	ft_free_place(char ***place)
{
	char		**str;
	int			i;

	str = *place;
	i = -1;
	while (++i < 4)
		free(str[i]);
	free(str);
}

void				ft_push_coordinates(int fd, t_tetramina **pointer)
{
	char		*str;
	int			i;
	char		**place;
	int			count;

	count = -1;
	place = ft_create_place();
	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		place[i] = ft_strcpy(place[i], str);
		free(str);
		i++;
		if (i == 4)
		{
			i = 0;
			if (get_next_line(fd, &str) > 0)
				free(str);
			count++;
			ft_push_struct_coor(place, count, pointer);
		}
	}
	ft_free_place(&place);
}
