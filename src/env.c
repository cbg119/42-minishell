/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:38:43 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/03 13:43:34 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				env_len(char *env[])
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void			init_env(char *env[])
{
	int		len;

	len = env_len(env);
	g_env = (char **)malloc(sizeof(char *) * (len + 1));
	if (g_env)
	{
		g_env[len--] = NULL;
		while (len >= 0)
		{
			g_env[len] = ft_strdup(env[len]);
			len--;
		}
	}
}

char			*get_env(char *env_var)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(env_var, "=");
	while (g_env[i])
	{
		if (ft_starts_with(temp, g_env[i]))
		{
			free(temp);
			return (ft_strchr(g_env[i], '=') + 1);
		}
		i++;
	}
	free(temp);
	return (NULL);
}
