/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:24:09 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:29:02 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*input;

	input = (char *)str;
	if (ft_strchr(str, c) == NULL)
		return (NULL);
	while (*input != '\0')
		input++;
	while (*input != c)
		input--;
	return (input);
}
