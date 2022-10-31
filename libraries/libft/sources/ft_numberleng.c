/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numberleng.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:18:52 by ahorling      #+#    #+#                 */
/*   Updated: 2021/10/25 15:33:32 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numberleng(long long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n > 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}
