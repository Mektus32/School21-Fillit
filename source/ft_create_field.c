/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:55:41 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/24 18:32:19 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field	*ft_create_field(int len, int count)
{
	int		i;
	int		j;
	t_field	*f;

	i = 0;
	j = 0;
	f = (t_field*)malloc(sizeof(t_field));
	f->field = (char**)malloc(sizeof(char*) * len);
	f->size = len;
	while (i < len)
	{
		f->field[i] = (char*)malloc(sizeof(char) * (len + 1));
		f->field[i][len] = '\0';
		while (j < len)
		{
			f->field[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	f->count = count;
	return (f);
}
