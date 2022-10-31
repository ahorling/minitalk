/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alexander <alexander@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 16:48:52 by alexander     #+#    #+#                 */
/*   Updated: 2022/08/23 17:26:30 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_length(int n)
{
	int	chars;

	chars = 0;
	if (n < 0)
	{
		n = n * -1;
		chars++;
	}
	while (n > 0)
	{
		n = n / 10;
		chars++;
	}
	return (chars);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		length;

	length = ft_length(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	string = (char *)malloc((length + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[length] = '\0';
	length--;
	if (n < 0)
	{
		string[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		string[length] = 48 + (n % 10);
		n = n / 10;
		length--;
	}
	return (string);
}
