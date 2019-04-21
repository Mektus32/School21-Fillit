/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:07:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/21 21:04:14 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tetramina	*ft_coordinates(int count)
{
	tetramina	*point;
	int			a;
	int			i;

	i = 0;
	a = -1;
	point = (tetramina*)malloc(sizeof(tetramina) * count);
	while (++a < count)
	{
		point[i].character = 'A' + i;
		i++;
	}
	return(point);
}
