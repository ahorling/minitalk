/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alexander <alexander@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 19:24:51 by alexander     #+#    #+#                 */
/*   Updated: 2022/08/23 17:26:38 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*input;
	char	*output;

	i = 0;
	input = (char *)src;
	output = (char *)dest;
	while (i < n)
	{
		output[i] = input[i];
		if ((unsigned char)input[i] == (unsigned char)c)
			return ((char *)dest + i + 1);
		i++;
	}
	return (NULL);
}
