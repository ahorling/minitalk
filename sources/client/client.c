/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 17:37:36 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/31 18:41:52 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

bool	parse_args(int argnum, char **arguments)
{
	int		i;
	bool	temp;

	i = 0;
	temp = true;
	if (arguments[i] == '\0')
		return (false);
	while (arguments[i] != '\0')
	{
		if (i == 0)
		{
			if (ft_isnum(arguments[i]) == false)
				return (false);
			temp = ft_isdigit(arguments[i]);
		}
		else if (ft_isdigit(arguments[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

void	convert_to_binary(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else if (((c >> bit) & 1) == 0)
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
	return ;
}

void	begin_message(t_info *info)
{
	int	i;

	i = 0;
	while (info->string[i])
	{
		convert_to_binary(info->string[i], info->pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info *info;

	info = malloc(sizeof(t_info));
	if (parse_args(argc, argv) == false)
	{
		write(2, "INPUT ERROR\n", 12);
		return (1);
	}
	info->pid = ft_atoi(argv[1]);
	info->string = argv[2];
	begin_message(info);
	free(info);
	return (0);
}