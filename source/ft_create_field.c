/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:55:41 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/21 15:55:43 by mtheodan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

field	*ft_create_field(int count)
{
	int		i;
	int		j;
	field	*f;

	i = 0;
	j = 0;
	//f = (char**)malloc(sizeof(char*) * count);
	f = (field*)malloc(sizeof(field));
	f->field = (char**)malloc(sizeof(char*) * count);
	while (i < count)
	{
		//write(1, "a", 1);
		// f[i] = (char*)malloc(sizeof(char) * row + 1);
		// f[row] = '\0';
		// while (f[i][j])
		f->field[i] = (char*)malloc(sizeof(char) * (count + 1));
		f->field[i][count] = '\0';
		//printf("%d\n", i);
		//printf("%d\n", count);
		//printf("%d\n", j);
		while (j < count)
		{
			//printf("%d\n", j);
			//write(1, "b", 1);	
			f->field[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return(f);
}