/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_whtspace.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 16:36:20 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/30 17:17:14 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_whtspce(const char *str)
{
	long	i;
	int		whtspce;

	i = 0;
	whtspce = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			whtspce++;
		else if (str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			whtspce++;
		else
			break ;
		i++;
	}
	return (whtspce);
}
