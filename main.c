/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:31:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/03/27 12:31:39 by mtheodan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "fillit.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_turn_l(tetramina *f, int count) // смещение влево 
{
	int 	i; // строка
	int		a;
	int		j; // столбец
	char	c;

	a = 0;
	i = 0;
	j = 0;
	while (a < count)
	{	
		while (f[a].tetraminas[0][0] == '.' && f[a].tetraminas[1][0] == '.'  // проверяем первый столбец, чтобы пустой был
		&& f[a].tetraminas[2][0] == '.' && f[a].tetraminas[3][0] == '.')
		{
			while (j < 4) // смещаем в строке по элементу 
			{
		//write(1, "a", 1);
				c = f[a].tetraminas[j][0];
				f[a].tetraminas[j][0] = f[a].tetraminas[j][1];
				f[a].tetraminas[j][1] = f[a].tetraminas[j][2];
				f[a].tetraminas[j][2] = f[a].tetraminas[j][3];
				f[a].tetraminas[j][3] = c;
				j++;
			}
			//write(1, "c", 1);
			j = 0;
		}
		a++;
	}
}

void 	ft_push_list(int fd, tetramina *f, int count) // читаем из файла и запихиваем в стуктуры 
{
	//write(1, "1", 1);
	char	buf[21];
	int 	re;
	int 	i;
	int		j;
	int		k;
	int		b;

	i = 0;
	j = 0;
	k = 0;
	b = 0;
	//re = read(fd, buf, 21);
	while (b < count)
	{
		//write(1, "a", 1);
		re = read(fd, buf, 21);
		buf[re-1] = '\0';
		while (buf[i] != '\0')
		{
			//write(1, "x", 1);
			if (buf[i] == '\n')
			{
			//	write(1, "b", 1);
				j = 0;
				k++;
			}
			else if (buf[i] == '#')
			{
				f[b].tetraminas[k][j] = f[b].character;
				j++;
			}
			else
			{
			//	write(1, "c", 1);
				f[b].tetraminas[k][j] = buf[i];
				j++; 
			}
			i++;
		}
		b++;
		j = 0;
		k = 0;
		i = 0;
	}
}
tetramina  *ft_create_arr(int count)
{
	//write(1, "2", 1);
	int i;
	int a;
	tetramina *field;
	field = (tetramina *)malloc(sizeof(tetramina) * count);
	i = 0;
	a = 0;
	while (a < count) // присваиваем букву чтобы потом поменять 
    	{
		//	write(1, "y", 1);
       	 	field[i].character = 65 + i;
       	 	i++;
       		a++;
    	}
	return (field);
}

void    ft_print_list(tetramina *f, int count)
{
//	write(1, "3", 1);
    int		j;
    int 	a;
	int 	column = 0; //  столбец
	int		row = 0; // строка

	a = 0;
	while (a < count)
	{
		while (column < 4)
		{
			//write(1, "x", 1);
			while (row < 4)
			{
				//write(1, "z", 1);
				write(1, &f[a].tetraminas[column][row], 1);
				row++;
			}
			write(1, "\n", 1);
			row = 0;
			column++;
		}
		write(1, "\n", 1);
		a++;
		row = 0;
		column = 0;
	}
}

int main(int argc, char **argv)
{
	int fd = open("./test2.txt", 0);

	tetramina *array;
	int count;

	count = 2;
	array = ft_create_arr(count);
	ft_push_list(fd, array, count);
	//ft_print_list(array, count);
	ft_turn_l(array, count);
	ft_print_list(array, count);
	return (0);
}