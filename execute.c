/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:41:57 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/01 10:15:09 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_env *env)
{
	if (ft_strcmp(env->com, "exit") == 0 || ft_strcmp(env->com, "quit") == 0)
		env->done = 1;
	else if (ft_strcmp(env->com, "clear") == 0)
		ft_printf("\033c");
	else if (ft_strcmp(env->com, "echo") == 0)
		echo(env);
	else if (ft_strcmp(env->com, "env") == 0)
		show_env(env->env_var);
	else if (ft_strcmp(env->com, "setenv") == 0)
		ft_setenv(env);
	else if (ft_strcmp(env->com, "unsetenv") == 0)
		ft_unsetenv(env);
	else if (ft_strcmp(env->com, "cd") == 0)
		ft_cd(env);
	else if (ft_strcmp(env->com, "pwd") == 0)
		ft_pwd(env);
	else
		ft_run(env);
}
