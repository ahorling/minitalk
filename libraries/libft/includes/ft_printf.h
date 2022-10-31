/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 13:26:19 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/05 17:48:20 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
void	print_char(int c, size_t *length);
void	print_percent(size_t *length);
void	print_string(char *string, size_t *length);
void	print_int(int i, size_t *length);
void	print_unsigned(unsigned int i, size_t *length);
void	print_hexa_lower(unsigned int i, size_t *length);
void	print_hexa_upper(unsigned int i, size_t *length);
void	print_pointer(unsigned long i, size_t *length);
int		print_format(char c, size_t *length, int *i);
void	ft_putstr(char *string);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_numberleng(long long n);
char	*ft_ulong_to_hexa_lower(unsigned long n);
char	*ft_ulong_to_hexa_upper(unsigned long n);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *string, int fd);

#endif