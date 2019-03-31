/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:21:24 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/31 12:08:08 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		change_dir(char *path, int print)
{
	char	cwd_path[PATH_MAX + 1];

	getcwd(cwd_path, PATH_MAX);
	if (chdir(path) == 0)
	{
		set_env_var("OLDPWD", cwd_path);
		if (print)
			ft_printf("%s\n", path);
		getcwd(cwd_path, PATH_MAX);
		set_env_var("PWD", cwd_path);
		return (0);
	}
	else
	{
		if (access(path, 0) == -1)
			ft_printf("cd: no such file or directory: %s\n", path);
		else if (access(path, 1) == -1)
			ft_printf("cd: permission denied: %s\n", path);
		return (1);
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

int				cd_b(char **command, int print)
{
	if (!command[1] || ft_strequ(command[1], "--"))
		return (change_dir(get_env("HOME"), 0));
	else if (ft_strequ(command[1], "-"))
		return (change_dir(get_env("OLDPWD"), 1));
	else
	{
		if (check_cd_error(command))
			return (1);
		return(change_dir(command[1], print));
	}
}
