/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 13:27:28 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:28:08 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		leng;
	char	*dupe;

	i = 0;
	leng = 0;
	while (str[i] != '\0')
	{
		leng++;
		i++;
	}
	i = 0;
	dupe = (char *)malloc((leng + 1) * sizeof(char));
	if (dupe == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dupe[i] = str[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}
