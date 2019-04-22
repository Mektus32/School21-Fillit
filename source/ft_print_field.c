/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:14:07 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/22 16:05:28 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_field(t_field *f, int count)
{
	int		i;
	int		j;

	
	j = -1;
	while (++j < count)
	{
		i = -1;
		while (++i < count)
			write(1, &f->field[j][i], 1);
		write(1, "\n", 1);
	}
}
