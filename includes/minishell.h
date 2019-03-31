/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:45:15 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/30 16:16:19 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**	MACROS
*/

# define PATH_MAX 4096
# define SUCCESS 0

/*
**	INCLUDES
*/

#include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

/*
**	GLOBALS
*/

char			**g_env;

/*
**	PROTOTYPES
*/

char			*get_env(char *env_var);

void			parse_input(char **command);
void			init_env(char *env[]);
void			display_prompt(void);
void			free_env(void);
int				exec_command(char **command);
int				env_len(char *env[]);

/*
**	BUILT-INS
*/

int				env_b(void);
int				cd_b(char **command, int print);
int				setenv_b(char **command);

#endif
