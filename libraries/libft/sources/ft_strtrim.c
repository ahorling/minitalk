/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 16:02:02 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:29:07 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *string, char const *set)
{
	size_t	endstr;
	char	*result;

	if (!string)
		return (NULL);
	if (string != 0 && !set)
		return (ft_strdup(string));
	while (ft_strchr(set, *string) && *string)
		string++;
	endstr = ft_strlen(string);
	while (ft_strchr(set, string[endstr - 1]) != NULL && endstr != 0)
		endstr--;
	result = ft_substr(string, 0, endstr);
	return (result);
}
