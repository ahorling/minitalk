/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexalower.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/23 14:33:05 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 17:26:29 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_hexlen(unsigned long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_ulong_to_hexa_lower(unsigned long n)
{
	int		i;
	char	*string;
	int		temp;

	i = ft_hexlen(n);
	temp = n;
	string = (char *)malloc((i + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[i] = '\0';
	if (n == 0)
		string[0] = '0';
	while (n != 0)
	{
		i--;
		temp = n % 16;
		if (temp < 10)
			string[i] = temp + 48;
		if (temp > 9)
			string[i] = temp + 87;
		n = n / 16;
	}
	return (string);
}
