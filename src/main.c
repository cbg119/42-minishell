/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:46:13 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/30 17:17:48 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		cleanup(char **command, char *line)
{
	int		i;

	i = 0;
	if (!command)
		return ;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	if (line)
		free(line);
	free(command);
}

int		main(int argc, char *argv[], char *env[])
{
	int		ret;
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
		ret = exec_command(command);
		ft_printf("%d\n\n", ret);
		cleanup(command, line);
		if (ret == -1)
			break ;
	}
	free_env();
	return (0);
}
