/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:06:32 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/27 23:29:59 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
static char		*handle_env_path(char *path)
{
	char	*new_path;

	if (!path)
		return (NULL);

}
*/

void	display_prompt(void)
{
	char	path[PATH_MAX + 1];

	getcwd(path, PATH_MAX);
	ft_printf("%s %s¯\\_(ツ)_/¯%s > %s", path, C_BLUE, C_MAGENTA, C_WHITE);
}
