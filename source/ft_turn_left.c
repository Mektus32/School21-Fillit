/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:43:43 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/20 16:52:50 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_turn_left(tetramina *arr, int count)
{
	int		i;
	int		a;
	int		j;
	char	c;

	a = -1;
	i = 0;
	while (++a < count)
		while (arr[a].tetraminas[0][0] == '.' && arr[a].tetraminas[1][0] == '.'
				&& arr[a].tetraminas[2][0] == '.' && arr[a].tetraminas[3][0] == '.')
		{
			j = -1;
			while (++j < 4)
			{
				c = arr[a].tetraminas[j][0];
				arr[a].tetraminas[j][0] = arr[a].tetraminas[j][1];
				arr[a].tetraminas[j][1] = arr[a].tetraminas[j][2];
				arr[a].tetraminas[j][2] = arr[a].tetraminas[j][3];
				arr[a].tetraminas[j][3] = c;
			}
		}
}
