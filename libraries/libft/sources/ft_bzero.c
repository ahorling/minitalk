/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:20:18 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:25:37 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_bzero(void *str, size_t size)
{
	size_t	index;
	char	*s;

	s = (char *)str;
	index = 0;
	while (index < size)
	{
		s[index] = '\0';
		index++;
	}
	return (str);
}
