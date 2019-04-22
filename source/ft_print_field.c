/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:14:07 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/22 21:01:54 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_field(t_field *map, int len)
{
	int		i;
	int		j;

	
	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < len)
			write(1, &map->field[j][i], 1);
		write(1, "\n", 1);
	}
	ft_free_field(&map, len);
	exit(0);
}
