/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:14:54 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/20 16:36:34 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_push_list(int fd, tetramina *arr, int count)
{
	char	*line;
	int		a;
	int		i;
	int		j;
	int		k;

	a = -1;
	while (++a < count)
	{
		j = 0;
		k = -1;
		while (++k < 5)
		{
			if (get_next_line(fd, &line) == -1)
			{
				printf("get_next_line = -1,file ft_push_list\n");
				exit(-1);
			}
			i = -1;
			while (line[++i] != '\0')
				if (line[i] == '.')
					arr[a].tetraminas[j][i] = line[i];
				else if (line[i] == '#')
					arr[a].tetraminas[j][i] = arr[a].character;
			j++;
		}
	}
}
