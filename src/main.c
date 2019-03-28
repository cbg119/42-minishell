/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:46:13 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/27 23:31:20 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_starts_with(char *to_start, char *str)
{
	int		i;

	i = 0;
	while (to_start[i] && str[i] && (to_start[i] == str[i]))
		i++;
	return (to_start[i] == '\0' ? 1 : 0);
}

int		main(int argc, char *argv[], char *env[])
{
	char	*line;

	(void)argc;
	(void)argv;
	init_env(env);
	while (1)
	{
		display_prompt();
		get_next_line(1, &line);
		ft_printf("Here is %s:\n", line);
		ft_printf("%s\n", get_env(line));
		free(line);
	}
	free_env();
}
