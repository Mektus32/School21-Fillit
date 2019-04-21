/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:18:54 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/21 18:18:56 by mtheodan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// void	ft_push_coordinates(int fd, tetramina *pointer, int count)
// {
// 	char	*line;
// 	int		a;
// 	int		i;
// 	int		j;
// 	int		k;
// 	int 	pos;

// 	a = -1;
// 	pos = 0;
// 	while (++a < count)
// 	{
// 		j = 0;
// 		k = -1;
// 		while (++k < 5)
// 		{
// 			if (get_next_line(fd, &line) == -1)
// 			{
// 				printf("get_next_line = -1,file ft_push_list\n");
// 				exit(-1);
// 			}
// 			i = -1;
// 			while (line[++i] != '\0')
// 			{
// 				if (line[i] == '#')
// 				{
// 					pointer[a].num_of_tetr.num[pos].x = i;
// 					pointer[a].num_of_tetr.num[pos].y = k;
// 				}
// 				else
// 					i++;
// 			}
// 			j++;
// 		}
// 	}
// }

static	void	ft_push_struct_coor(char **place, int count, tetramina **pointer)
{
	int		column;
	int 	row;
	int		num;

	num = 0;
	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			if (place[row][column] == '#')
			{
				(*pointer)[count].num_of_tetr.num[num].x = column;
				(*pointer)[count].num_of_tetr.num[num].y = row;
				num++;
			}
			column++;
		}
		row++;
	}
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

void				ft_push_coordinates(int fd, tetramina **pointer)
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
