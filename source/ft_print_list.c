/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:37:54 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/20 16:43:59 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_list(tetramina *arr, int count)
{
	int		a;
	int		column;
	int		row;

	a = -1;
	while (++a < count)
	{
		column = -1;
		while (++column < 4)
		{
			row = -1;
			while (++row < 4)
				write(1, &arr[a].tetraminas[column][row], 1);
			write(1, "\n", 1);
		}
		write(1, "\n", 1);
	}
}
