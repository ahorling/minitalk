/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:21:22 by ahorling      #+#    #+#                 */
/*   Updated: 2022/11/04 20:28:02 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

char	*string_set(char c, char *string)
{
	char	cha[2];
	char	*ret;

	cha[0] = c;
	cha[1] = '\0';
	if (string == NULL)
	{
		ret = malloc(2 * sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = c;
		ret[1] = '\0';
	}
	else
	{
		ret = ft_strjoin(string, cha);
		free(string);
	}
	return (ret);
}

void	create_string(char c)
{
	static char	*string;
	char		*temp;

	if (c == '\0')
	{
		ft_printf("%s\n", string);
		free(string);
		string = NULL;
		return ;
	}
	else
		string = string_set(c, string);
	return ;
}

void	signal_handler(int signal, siginfo_t *info, void *options)
{
	static int	i = 0;
	static char	c = 0;
	static int	pid;

	(void)options;
	if (info->si_pid != 0)
		pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		create_string(c);
		if (c == '\0')
		{
			i = 0;
			c = 0;
			kill(pid, SIGUSR2);
			return ;
		}
		i = 0;
		c = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();
}
