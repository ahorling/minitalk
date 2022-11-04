/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 17:37:36 by ahorling      #+#    #+#                 */
/*   Updated: 2022/11/04 20:03:28 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

bool	parse_args(int argnum, char **arguments)
{
	int		i;
	bool	temp;

	i = 0;
	temp = true;
	if (argnum != 3)
		return (false);
	if (ft_atoi(arguments[1]) == 0)
		return (false);
	while (arguments[1][i])
	{
		if (i == 0)
		{
			temp = ft_isnum(arguments[1][i]);
			i++;
		}
		if (temp == false)
			return (false);
		if (ft_isdigit(arguments[1][i] == 0) && temp == true)
			return (false);
		i++;
	}
	return (true);
}

t_info	*info_manage(void)
{
	static t_info	info;

	return (&info);
}

int	convert_to_binary(char c, int pid, int bit)
{
	if (c & (1 << bit))
		return (kill(pid, SIGUSR1));
	else
		return (kill(pid, SIGUSR2));
}

void	begin_message(int signal)
{
	static size_t	i = 0;
	static int		bit = 1;
	t_info			*info;
	int				itemp;
	int				bittemp;

	if (signal == SIGUSR2)
		exit(0);
	info = info_manage();
	bittemp = bit;
	itemp = i;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		i++;
	}
	convert_to_binary(info->string[itemp], info->pid, bittemp);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = info_manage();
	if (parse_args(argc, argv) == false)
	{
		write(2, "INPUT ERROR\n", 12);
		return (1);
	}
	info->pid = ft_atoi(argv[1]);
	info->string = argv[2];
	signal(SIGUSR1, begin_message);
	signal(SIGUSR2, begin_message);
	if (convert_to_binary(info->string[0], info->pid, 0) != 0)
	{
		write(2, "PID ERROR\n", 10);
		exit(1);
	}
	while (true)
		pause();
}
