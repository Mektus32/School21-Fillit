/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:29:08 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/20 16:52:40 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tetramina		*ft_create_arr(int count)
{
	int			i;
	int			a;
	tetramina	*field;

	field = (tetramina*)malloc(sizeof(tetramina) * count);
	i = 0;
	a = -1;
	while (++a < count)
	{
		field[i].character = 'A' + i;
		i++;
	}
	return (field);
}
