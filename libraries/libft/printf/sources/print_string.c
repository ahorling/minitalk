/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:54:19 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 16:37:08 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_string(char *string, size_t *length)
{
	int		len;

	if (string == NULL)
		string = "(null)";
	len = ft_strlen(string);
	ft_putstr(string);
	*length = *length + len;
	return ;
}
