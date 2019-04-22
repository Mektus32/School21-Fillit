/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:59:14 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/22 22:07:01 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 21
# define TRUE 1
# define FALSE 0

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_tetramina
{
	struct		s_coordinates
	{
		int x;
		int y;
	}		num[4];
	char	character;
}				t_tetramina;

typedef	struct	s_field
{
	char	**field;
	int		size;
	int		count;
}				t_field;

int				get_next_line(int fd, char **line);
void			ft_print_error(void);
void			ft_check_valid_files(int fd);
void			ft_print_field(t_field *map, int len);
t_field			*ft_create_field(int len, int count);
int				ft_square(int count);
t_tetramina		*ft_coordinates(int count);
void			ft_push_coordinates(int fd, t_tetramina **pointer);
int				ft_check_valid_figures(int fd);
void			ft_free_field(t_field **map, int len);
int				ft_entry_figure(t_tetramina *arr, t_field *map);

#endif
