/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isnum.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 16:34:00 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 17:16:14 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

bool	ft_isnum(char c)
{
	if (c == '-' || c == '+' || (c >= '0' && c <= '9'))
		return (true);
	else
		return (false);
}
