/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:43:41 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/30 18:12:43 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	is_bulitin and exec_builtin could definitely be combined, or re formatted
**	as a dispatch table for cleaner code. I'll implement it later.
*/

static int is_builtin(char *cmd)
{
	if (ft_strcmp("cd", cmd) == 0 ||
	ft_strcmp("exit", cmd) == 0 ||
	ft_strcmp("env", cmd) == 0 ||
	ft_strcmp("setenv", cmd) == 0 ||
	ft_strcmp("unsetenv", cmd) == 0)
		return (1);
	return (0);
}

static int	exec_builtin(char **command)
{
	if (ft_strcmp("cd", command[0]) == 0)
		return(cd_b(command, 0));
	else if (ft_strcmp("env", command[0]) == 0)
		return(env_b());
	else if (ft_strcmp("exit", command[0]) == 0)
		return (-1);
	else if (ft_strcmp("setenv", command[0]) == 0)
		return (setenv_b(command));
	else if (ft_strcmp("unsetenv", command[0]) == 0)
		return (unsetenv_b(command));
	return (1);
}

int			exec_command(char **command)
{
	if (!command || !*command)
		return (1);
	if (is_builtin(command[0]))
		return (exec_builtin(command));
	else
	{
		ft_printf("minishell: command not found: %s\n", command[0]);
	}
	return (1);
}
