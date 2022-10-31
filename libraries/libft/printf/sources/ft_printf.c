/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 11:57:29 by ahorling      #+#    #+#                 */
/*   Updated: 2022/08/23 16:37:21 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	analyze_conversion(va_list arg, size_t *length, char conversion_flag)
{
	if (conversion_flag == 'i' || conversion_flag == 'd')
		print_int(va_arg(arg, int), length);
	else if (conversion_flag == 'c')
		print_char(va_arg(arg, int), length);
	else if (conversion_flag == 's')
		print_string(va_arg(arg, char *), length);
	else if (conversion_flag == '%')
		print_percent(length);
	else if (conversion_flag == 'x')
		print_hexa_lower(va_arg(arg, unsigned int), length);
	else if (conversion_flag == 'X')
		print_hexa_upper(va_arg(arg, unsigned int), length);
	else if (conversion_flag == 'u')
		print_unsigned(va_arg(arg, unsigned int), length);
	else if (conversion_flag == 'p')
		print_pointer(va_arg(arg, unsigned long), length);
}

int	print_format(char c, size_t *length, int *i)
{
	if (c != '%' && c != '\0')
	{
		ft_putchar(c);
		*i += 1;
		*length += 1;
		return (0);
	}
	else if (c == '%')
		return (1);
	else
		return (2);
}

int	ft_printf(const char *format, ...)
{
	size_t	length;
	int		i;
	va_list	arg;
	int		flag;

	length = 0;
	i = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		flag = print_format(format[i], &length, &i);
		if (flag == 1)
		{
			i++;
			while (format[i] != 'i' && format[i] != 'd' && format[i] != 'c'
				&& format[i] != 's' && format[i] != '%' && format[i] != 'x'
				&& format[i] != 'X' && format[i] != 'u' && format[i] != 'p')
				i++;
			analyze_conversion(arg, &length, format[i]);
			i++;
		}
	}
	va_end(arg);
	return (length);
}
