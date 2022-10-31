/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 14:39:54 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:28:12 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fullstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fullstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (fullstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		fullstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		fullstr[i + j] = s2[j];
		j++;
	}
	fullstr[i + j] = '\0';
	return (fullstr);
}
