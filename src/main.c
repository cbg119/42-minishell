/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:46:13 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/29 21:54:21 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char *argv[], char *env[])
{
	char	*line;
	char	**command;

	(void)argc;
	(void)argv;
	init_env(env);
	while (1)
	{
		display_prompt();
		get_next_line(1, &line);
		command = ft_strsplit(line, ' ');
		parse_input(command);
		//is builtin? exec builtin.
		//is system command? run system command
		//is folder/executable? chdir folder, run executable
		//error
		if (exec_command(command) == -1)
		{
			free(line);
			break ;
		}
		free(line);
	}
	free_env();
}
