/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:43:41 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/29 22:18:10 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int is_builtin(char *cmd)
{
	if (ft_strcmp("cd", cmd) == 0 ||
	ft_strcmp("exit", cmd) == 0 ||
	ft_strcmp("env", cmd) == 0)
		return (1);
	return (0);
}

static int	exec_builtin(char **command)
{
	if (ft_strcmp("cd", command[0]) == 0)
		cd_b(command, 0);
	if (ft_strcmp("env", command[0]) == 0)
		env_b();
	if (ft_strcmp("exit", command[0]) == 0)
		return (-1);
	return (0);
}

int			exec_command(char **command)
{
	if (!command || !*command)
		return (1);
	if (is_builtin(command[0]))
	{
		if (exec_builtin(command) == -1)
			return (-1);
		return (0);
	}
	else
	{
		ft_printf("minishell: command not found: %s\n", command[0]);
	}
	return (1);
}
