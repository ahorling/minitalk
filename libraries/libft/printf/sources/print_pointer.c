/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_pointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 16:09:08 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 16:37:05 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_pointer(unsigned long i, size_t *length)
{
	char	*string;

	string = ft_ulong_to_hexa_lower(i);
	if (string == NULL)
		return ;
	ft_putstr("0x");
	ft_putstr(string);
	*length = *length + ft_strlen(string) + 2;
	free (string);
	return ;
}
