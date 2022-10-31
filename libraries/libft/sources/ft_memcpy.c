/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:19:47 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:26:53 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*output;
	char	*input;

	i = 0;
	output = (char *)dest;
	input = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < size)
	{
		output[i] = input[i];
		i++;
	}
	return (dest);
}
