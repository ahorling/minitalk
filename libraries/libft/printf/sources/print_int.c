/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:12:28 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 16:37:01 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_int(int i, size_t *length)
{
	int			len;

	if (i > 2147483647 || i < -2147483648)
		return ;
	len = ft_numberleng(i);
	ft_putnbr(i);
	*length = *length + len;
	return ;
}
