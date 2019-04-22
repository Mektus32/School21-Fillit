/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:55:41 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/22 16:07:58 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field	*ft_create_field(int count)
{
	int		i;
	int		j;
	t_field	*f;

	i = 0;
	j = 0;
	f = (t_field*)malloc(sizeof(t_field));
	f->field = (char**)malloc(sizeof(char*) * count);
	while (i < count)
	{
		f->field[i] = (char*)malloc(sizeof(char) * (count + 1));
		f->field[i][count] = '\0';
		while (j < count)
		{
			f->field[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return(f);
}
