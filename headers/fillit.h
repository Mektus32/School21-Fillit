# ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 21

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct 	s_tetramina
{
	char	character;
	char	tetraminas[4][4];
}				tetramina;

tetramina	*ft_create_arr(int count);
void		ft_turn_left(tetramina *arr, int count);
int			get_next_line(int fd, char **line);
void		ft_push_list(int fd, tetramina *arr, int count);
void		ft_print_list(tetramina *arr, int count);
void		ft_print_error(void);
void		ft_check_valid_files(int fd);
int			ft_check_valid_figures(int fd);

#endif
