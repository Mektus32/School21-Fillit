/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:19:04 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/25 17:01:24 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_count_blocks(char *str)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
		if (str[i] == '#')
			count++;
	return (count);
}

static	void	ft_check_character(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] != '.' && str[i] != '#')
			ft_print_error();
}

void			ft_check_valid_files(int fd)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (get_next_line(fd, &str) > 0)
	{
		if (i == 4 && ft_strlen(str) != 0)
			ft_print_error();
		if (i != 4 && ft_strlen(str) != 4)
			ft_print_error();
		i++;
		if (i == 5)
			i = 0;
		ft_check_character(str);
		count += ft_count_blocks(str);
		free(str);
	}
	if (count > 129 || count == 0 || (i != 4 && i != 0) ||
			(i == 0 && count % 2 == 0))
		ft_print_error();
	close(fd);
}
