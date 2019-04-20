/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:09:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/20 14:56:34 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char *str;

	str = (char*)arr;
	while (n--)
	{
		if (*(unsigned char*)str != (unsigned char)c)
			str++;
		else
			return (str);
	}
	return (NULL);
}
