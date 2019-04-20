/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtheodan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:31:37 by mtheodan          #+#    #+#             */
/*   Updated: 2019/04/20 20:16:36 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int main(void)
{
	int fd = open("./test2.txt", 0);

	tetramina *array;
	int count;

	count = 2;
	
	ft_check_valid_files(fd);
	array = ft_create_arr(count);
	fd = open("./test2.txt", 0);
	ft_push_list(fd, array, count);
	ft_turn_left(array, count);
	ft_print_list(array, count);
	close(fd);
	return (0);
}
