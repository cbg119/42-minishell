/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:34:16 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/31 13:17:47 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse_input(char **command)
{
	char	*home;
	char	*temp;
	int		i;

	i = 0;
	home = get_env("HOME");
	while (command[i])
	{
		if (command[i][0] == '~')
		{
			temp = ft_strjoin(home, ft_strchr(command[i], '~') + 1);
			free(command[i]);
			command[i] = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
}
