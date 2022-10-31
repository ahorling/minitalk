/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_unsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/23 13:15:12 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 16:37:11 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_putunsigned(n / 10);
		ft_putunsigned(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
	return ;
}

void	print_unsigned(unsigned int i, size_t *length)
{
	int			len;

	len = ft_numberleng(i);
	ft_putunsigned(i);
	*length = *length + len;
}
