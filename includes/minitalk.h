/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:26:56 by ahorling      #+#    #+#                 */
/*   Updated: 2022/11/04 19:35:27 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libraries/libft/includes/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdbool.h>

//struct containing the info passed to client
typedef struct s_info
{
	int		pid;
	char	*string;
}	t_info;

//server functions
void	signal_handler(int signal, siginfo_t *info, void *options);
void	create_string(char c);

//client functions
void	begin_message(int signal);
int		convert_to_binary(char c, int pid, int bit);
bool	parse_args(int argnum, char **arguments);
t_info	*info_manage(void);

#endif