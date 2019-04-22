/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:07:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/22 16:07:29 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetramina	*ft_coordinates(int count)
{
	t_tetramina	*point;
	int			a;
	int			i;

	i = 0;
	a = -1;
	point = (t_tetramina*)malloc(sizeof(t_tetramina) * count);
	while (++a < count)
	{
		point[i].character = 'A' + i;
		i++;
	}
	return(point);
}
