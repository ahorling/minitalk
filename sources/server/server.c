/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:21:22 by ahorling      #+#    #+#                 */
/*   Updated: 2022/11/04 19:33:48 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	create_string(char c)
{
	static char	*string;
	static int	i = 0;
	char		cha[2];

	cha[0] = c;
	cha[1] = '\0';
	if (c == '\0')
	{
		ft_printf("%s\n", string);
		free(string);
		string = NULL;
		return ;
	}
	if (string == NULL)
	{
		string = malloc(2 * sizeof(char));
		if (!string)
			return ;
		string[0] = c;
		string[1] = '\0';
	}
	else
		string = ft_strjoin(string, cha);
	i++;
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
