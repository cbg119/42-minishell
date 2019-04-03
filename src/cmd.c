/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:36:23 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/02 16:51:56 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		is_executable(char **command, char *bin, struct stat info)
{
	if (S_ISREG(info.st_mode))
	{
		if (info.st_mode & S_IXUSR)
			return (exec_path(bin, command));
		else
			ft_printf("minishell: permission denied: %s\n", bin);
		free(bin);
		return (1);
	}
	free(bin);
	return (1);
}

char	*in_path(char **command)
{
	int				i;
	char			**bin;
	char			*path;
	struct stat		info;

	i = 0;
	bin = ft_strsplit(get_env("PATH"), ':');
	while (bin[i])
	{
		if (ft_starts_with(bin[i], command[0]))
			path = ft_strdup(command[0]);
		else
			path = ft_pathjoin(bin[i], command[0]);
		if (lstat(path, &info) == -1)
			free(path);
		else
		{
			ft_freestrarray(bin);
			return (path);
		}
		i++;
	}
	ft_freestrarray(bin);
	return (NULL);
}
