/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: alexander <alexander@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 16:28:53 by alexander     #+#    #+#                 */
/*   Updated: 2022/10/30 19:16:04 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(const char *str)
{
	long	value;
	long	i;
	int		neg;

	i = ft_whtspce(str);
	value = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10;
		value = value + str[i] - '0';
		i++;
	}
	if (value == 0 && neg == -1)
		return (0);
	return (value * neg);
}
