/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:41:10 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:26:28 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	total;
	size_t	i;
	char	*allocated;

	i = 0;
	total = nitems * size;
	allocated = malloc(total);
	if (allocated == NULL)
		return (NULL);
	while (total - i > 0)
	{
		allocated[i] = 0;
		i++;
	}
	return ((void *)allocated);
}
