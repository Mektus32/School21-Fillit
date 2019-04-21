# ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 21

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct 	s_tetramina
{
	struct {
		struct s_coordinates{
			int x;
			int y;
		}	s_coordinates;
		struct s_coordinates num[4];
	}			num_of_tetr;
	char	character;
}				tetramina;

typedef	struct 	s_field
{
	char	**field;
	int		size;
}				field;

int			get_next_line(int fd, char **line);
void		ft_print_error(void);
void		ft_check_valid_files(int fd);
void		ft_print_field(field *f, int count);
field		*ft_create_field(int count);
int			ft_square(int count);
tetramina	*ft_coordinates(int count);
void		ft_push_coordinates(int fd, tetramina **pointer);
int			ft_check_valid_figures(int fd);

#endif
