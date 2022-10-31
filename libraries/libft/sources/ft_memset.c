/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:44:17 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:27:04 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	size_t	index;
	char	*s;

	s = (char *)str;
	index = 0;
	while (index < size)
	{
		s[index] = c;
		index++;
	}
	return (str);
}
