/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:02:38 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/30 18:51:57 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		unset_env_var(char *key)
{
	int		i;
	int		j;
	int		len;
	char	*key_temp;
	char	**new_env;

	i = 0;
	j = 0;
	len = env_len(g_env) - 1;
	key_temp = ft_strjoin(key, "=");
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	new_env[len] = 0;
	while (i < len && g_env[j])
	{
		if (!ft_starts_with(key_temp, g_env[j]))
		{
			new_env[i] = ft_strdup(g_env[j]);
			i++;
		}
		j++;
	}
	free(key_temp);
	free_env();
	g_env = new_env;
	return (0);
}

int				unsetenv_b(char **command)
{
	if (!command[1])
		ft_printf("unsetenv: too few arguments\n");
	else if (command[1] && command[2])
		ft_printf("unsetenv: too many arguments\n");
	else if (get_env(command[1]) == NULL)
		ft_printf("unsetenv: %s: variable not found\n", command[1]);
	else
		return (unset_env_var(command[1]));
	return (1);
}
