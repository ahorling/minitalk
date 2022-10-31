/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:26:56 by ahorling      #+#    #+#                 */
/*   Updated: 2022/10/31 16:18:49 by ahorling      ########   odam.nl         */
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
    int pid;
    char *string;
}   t_info;

//server functions
void	signal_handler(int signal);

//client functions
void	begin_message(t_info *info);
void	convert_to_binary(char c, int pid);
bool	parse_args(int argnum, char **arguments);

#endif