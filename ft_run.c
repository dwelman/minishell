/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 11:07:28 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 13:34:07 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_bin(t_env *env)
{
	char	**paths;
	char	*path_var;
	char	*bin;
	int		i;

	i = 0;
	path_var = get_env("PATH", env);
	if (path_var != NULL)
	{
		path_var = ft_strchr(path_var, '/');
		paths = ft_strsplit(path_var, ':');
		while (paths[i])
		{
			if (env->com[0] == '.')
				bin = env->com;
			else
				bin = build_path(paths[i], env->com);
			if (execve(bin, env->argv, NULL) != -1)
				return (1);
			i++;
		}
	}
	return (-1);
}

void	ft_run(t_env *env)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	stat = 1;
	if (fork > 0)
	{
		wait(&stat);
	}
	if (pid == 0 && env->com != NULL)
	{
		if (run_bin(env) == -1)
		{
			if (get_env("PATH", env) == NULL)
				ft_printf("PATH variable not found\n");
			else if (ft_strlen(env->com) > 0 && ft_strcmp(env->com, "\t") != 0)
				ft_printf("unknown command: %s\n", env->com);
		}
		exit(0);
	}
}
