/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:21:24 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/28 19:49:39 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		change_dir(char *path, int print)
{
	if (chdir(path) == 0)
	{
		if (print)
			ft_printf("%s\n", path);
	}
	else
	{
		if (access(path, 0) == -1)
			ft_printf("cd: no such file or directory: %s\n", path);
		else if (access(path, 1) == -1)
			ft_printf("cd: permission denied: %s\n", path);
	}
}

static int		check_cd_error(char **command)
{
	if (command[2])
	{
		ft_printf("cd: too many arguments\n");
		return (1);
	}
	return (0);
}

void			cd_b(char **command, int print)
{
	if (!command[1])
		change_dir(get_env("HOME"), 0);
	else
	{
		if (check_cd_error(command))
			return ;
		change_dir(command[1], print);
	}
}
