/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:07:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/25 15:19:54 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetramina	*ft_coordinates(int count_figure)
{
	t_tetramina	*array;
	int			a;
	int			i;

	i = 0;
	a = -1;
	array = (t_tetramina*)malloc(sizeof(t_tetramina) * count_figure);
	while (++a < count_figure)
	{
		array[i].character = 'A' + i;
		i++;
	}
	return (array);
}
