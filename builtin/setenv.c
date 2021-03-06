/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:34:25 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/02 17:09:05 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	find_env_index(char *key)
**
**	OBJECTIVE: find key within g_env, return index if found,
**	otherwise return -1
*/

static int		find_env_index(char *key)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(key, "=");
	while (g_env[i])
	{
		if (ft_starts_with(temp, g_env[i]))
		{
			free(temp);
			return (i);
		}
		i++;
	}
	free(temp);
	return (-1);
}

/*
**	new_env_var(char *key, char *value)
**
**	OBJECTIVE: Allocate new environmental variable array, copy over existing
**	contents, then add new key:value pair. Then free g_env and assign
**	it to new array
*/

static void		new_env_var(char *key, char *value)
{
	int		i;
	int		len;
	char	*key_temp;
	char	*new_var;
	char	**new_env;

	i = 0;
	len = env_len(g_env) + 1;
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	new_env[len--] = 0;
	while (g_env[i])
	{
		new_env[i] = ft_strdup(g_env[i]);
		free(g_env[i]);
		i++;
	}
	free(g_env);
	key_temp = ft_strjoin(key, "=");
	new_var = ft_strjoin(key_temp, value);
	new_env[i] = ft_strdup(new_var);
	free(key_temp);
	free(new_var);
	g_env = new_env;
}

/*
**	set_env_var(char *key, char *value)
**
**	OBJECTIVE: If key:value pair exists, free, alloc, and set new
**	key:value pair in g_env
*/

int				set_env_var(char *key, char *value)
{
	int		i;
	char	*key_temp;
	char	*temp;

	i = find_env_index(key);
	if (i != -1)
	{
		key_temp = ft_strjoin(key, "=");
		temp = ft_strjoin(key_temp, value);
		free(key_temp);
		free(g_env[i]);
		g_env[i] = ft_strdup(temp);
		free(temp);
		return (0);
	}
	else if (i == -1)
		new_env_var(key, value);
	return (0);
}

/*
**	Just a wrapper function for set_env_var
*/

int				setenv_b(char **command)
{
	if (!command[1])
		ft_printf("setenv: too few arguments\n");
	else if (command[1] && command[2] && command[3])
		ft_printf("setenv: too many arguments\n");
	else
	{
		if (!command[2])
			return (set_env_var(command[1], ""));
		return (set_env_var(command[1], command[2]));
	}
	return (1);
}
