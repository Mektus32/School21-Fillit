/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:59:14 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/25 16:18:05 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 21
# define TRUE 1
# define FALSE 0

# include "libft.h"
# include <fcntl.h>

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
t_field			*ft_create_field(int map_size, int count_figure);
int				ft_square(int count);
t_tetramina		*ft_coordinates(int count_figure);
void			ft_push_coordinates(int fd, t_tetramina **pointer);
int				ft_check_valid_figures(int fd);
void			ft_free_field(t_field **map, int len);
int				ft_entry_figure(t_tetramina *arr, t_field **map);
t_field			**ft_change_map(t_field **map, int map_size, int new_map_size);
void			ft_usage(void);

#endif
