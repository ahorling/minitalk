/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 14:06:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:29:10 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	char	*string;

	i = 0;
	string = (char *)s;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(string) < start)
		len = 0;
	else if ((ft_strlen(string) + start) < len)
		len = ft_strlen(string) + start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = string[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
