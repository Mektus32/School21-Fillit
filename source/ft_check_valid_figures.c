/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_figures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:09:53 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/22 15:51:11 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_check_square(char **place)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (place[i][j] == '#' && place[i][j + 1] == '#' &&
					place[i + 1][j] == '#' && place[i + 1][j + 1] == '#'
					&& i != 3 && j != 3)
				return (1);
	}
	ft_print_error();
	return (0);
}

static	int		ft_check_side(char **place)
{
	int			i;
	int			j;
	int			count;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (j != 0 && place[i][j] == '#' && place[i][j - 1] == '#')
				count++;
			if (j != 3 && place[i][j] == '#' && place[i][j + 1] == '#')
				count++;
			if (i != 0 && place[i][j] == '#' && place[i - 1][j] == '#')
				count++;
			if (i != 3 && place[i][j] == '#' && place[i + 1][j] == '#')
				count++;
		}
	}
	if (count == 6 || (count == 8 && ft_check_square(place)))
		return (1);
	ft_print_error();
	return (0);
}

static	char	**ft_create_place(void)
{
	char		**place;
	int			i;

	place = (char**)malloc(sizeof(char*) * 4);
	i = -1;
	while (++i < 4)
	{
		place[i] = (char*)malloc(sizeof(char) * 5);
		place[i][4] = '\0';
	}
	return (place);
}

static	void	ft_free_place(char ***place, char **strcp)
{
	char		**str;
	int			i;

	str = *place;
	i = -1;
	while (++i < 4)
		free(str[i]);
	free(str);
	if (ft_strlen(*strcp) == 1)
		ft_print_error();
}

int				ft_check_valid_figures(int fd)
{
	char		*str;
	int			figures;
	int			i;
	char		**place;

	figures = 0;
	place = ft_create_place();
	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		place[i] = ft_strcpy(place[i], str);
		free(str);
		i++;
		if (i == 4)
		{
			i = 0;
			if (get_next_line(fd, &str) > 0)
				free(str);
			figures += ft_check_side(place);
		}
	}
	ft_free_place(&place, &str);
	return (figures);
}
