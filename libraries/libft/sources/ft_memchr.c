/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alexander <alexander@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 12:52:12 by alexander     #+#    #+#                 */
/*   Updated: 2022/08/23 17:26:43 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *str, int ch, size_t size)
{
	char	*input;
	size_t	i;

	i = 0;
	input = (char *)str;
	while (i < size)
	{
		if (input[i] == ch)
			return (&input[i]);
		i++;
	}
	return (NULL);
}
