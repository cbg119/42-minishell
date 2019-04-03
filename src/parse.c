/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:34:16 by cbagdon           #+#    #+#             */
/*   Updated: 2019/04/02 17:16:31 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define NOT_SPECIAL(c) ((c != '$' && c != ':') ? 1 : 0)

static char		*parse_env_var(char *str, int index)
{
	char	*new;

	new = ft_strdup("");
	while (str[index] && !IS_SPACE(str[index]) && str[index] != '$' &&
	str[index] != ':')
		new = ft_strjoinchf(new, str[index++]);
	return (new);
}

static char		*parse_command(char *str, int i)
{
	char	*var;
	char	*new;

	new = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$')
		{
			var = parse_env_var(str, i++ + 1);
			new = ft_strjoinf(new, ((get_env(var)) ? get_env(var) : "$"));
			free(var);
			while (str[i] && !IS_SPACE(str[i]) && NOT_SPECIAL(str[i]))
				i++;
		}
		else if ((i == 0 || (i != 0 && IS_SPACE(str[i - 1]))) &&
		str[i] == '~' && str[i + 1] != '$')
		{
			new = ft_strjoinf(new, get_env("HOME"));
			i++;
		}
		else
			new = ft_strjoinchf(new, str[i++]);
	}
	free(str);
	return (new);
}

void			parse_input(char **command)
{
	int		i;

	i = 0;
	if (!command || !*command)
		return ;
	while (command[i])
	{
		if (ft_strchr(command[i], '$') != NULL ||
		ft_strchr(command[i], '~') != NULL)
			command[i] = parse_command(command[i], 0);
		i++;
	}
}
