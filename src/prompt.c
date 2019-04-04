/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:06:32 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/03 23:15:10 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*handle_env_path(char *path)
{
	if (!path)
		return (NULL);
	if (get_env("HOME") != NULL)
	{
		if (ft_strcmp(path, get_env("HOME")) == 0)
			return (ft_strdup("~"));
		else if (ft_starts_with(get_env("HOME"), path))
			return (ft_strjoin("~", &path[ft_strlen(get_env("HOME"))]));
	}
	return (ft_strdup(path));
}

char			*get_handled_path(void)
{
	char	*h_path;
	char	*result;
	char	path[PATH_MAX + 1];

	getcwd(path, PATH_MAX);
	h_path = handle_env_path(path);
	result = ft_strjoin(h_path, " ¯\\_(ツ)_/¯ > ");
	free(h_path);
	return (result);
}

void			display_prompt(void)
{
	char	*formatted_path;

	formatted_path = get_handled_path();
	ft_printf(C_BLUE);
	ft_putstr(formatted_path);
	ft_printf(C_WHITE);
	free(formatted_path);
}
