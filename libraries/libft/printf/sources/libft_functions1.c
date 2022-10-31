/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_functions1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:38:02 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 16:42:06 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *string)
{
	int	len;

	len = ft_strlen(string);
	if (string != NULL)
		write(1, string, len);
}

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

char	*ft_ulong_to_hexa_upper(unsigned long n)
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
		temp = n % 16;
		if (temp < 10)
			string[i - 1] = temp + 48;
		if (temp > 9)
			string[i - 1] = temp + 55;
		n = n / 16;
		i--;
	}
	return (string);
}
