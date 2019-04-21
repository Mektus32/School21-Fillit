/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:14:07 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/21 16:14:08 by mtheodan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_field(field *f, int count)
{
	int		i;
	int		j;

	
	j = -1;
	while (++j < count)
	{
		//write(1, "c", 1);
		i = -1;
		while (++i < count)
		{
			write(1, &f->field[j][i], 1);
			//write(1, "d", 1);
		}
		write(1, "\n", 1);
	}
}