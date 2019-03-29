/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:06:32 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/28 17:09:30 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*handle_env_path(char *path)
{

	if (!path)
		return (NULL);
	if (ft_strcmp(path, get_env("HOME")) == 0)
		return(ft_strdup("~"));
	else if (ft_starts_with(get_env("HOME"), path))
		return (ft_strjoin("~", &path[ft_strlen(get_env("HOME"))]));
	else
		return(ft_strdup(path));
}

void	display_prompt(void)
{
	char	path[PATH_MAX + 1];
	char	*formatted_path;

	getcwd(path, PATH_MAX);
	formatted_path = handle_env_path(path);
	ft_printf("%s %s¯\\_(ツ)_/¯%s > %s", formatted_path, C_BLUE,
	C_MAGENTA, C_WHITE);
	free(formatted_path);
}
