/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:45:15 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/27 23:31:51 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**	MACROS
*/

# define PATH_MAX 4096

/*
**	INCLUDES
*/

#include "../libft/includes/libft.h"
#include <unistd.h>

/*
**	GLOBALS
*/

char			**g_env;

/*
**	PROTOTYPES
*/

int				ft_starts_with(char *to_start, char *str);

char			*get_env(char *env_var);

void			init_env(char *env[]);
void			display_prompt(void);
void			free_env(void);

#endif
