/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:03:18 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/01 10:13:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*build_path(char *tmp, char *add)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	path = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(add) + 2));
	while (tmp[i] != '\0')
	{
		path[i] = tmp[i];
		i++;
	}
	path[i] = '/';
	i++;
	while (add[j] != '\0')
	{
		path[i] = add[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

void	change_path(char *path, t_env *env)
{
	char	*old_pwd;

	old_pwd = NULL;
	if (access(path, F_OK) != 0)
	{
		ft_printf("cd: No such file or directory\n");
		return ;
	}
	if (access(path, R_OK) != 0)
	{
		ft_printf("cd: Permission denied\n");
		return ;
	}
	if (chdir(path) != 0)
	{
		ft_printf("cd: Not a directory\n");
		return ;
	}
	if (find_line("PWD", env->env_var) != -1)
	{
		old_pwd = env->env_var[find_line("PWD", env->env_var)];
		old_pwd = ft_strchr(old_pwd, '=');
		old_pwd++;
		change_env("OLDPWD", old_pwd, env);
	}
}

int		cd_aux(char **tmp, char **path, t_env *env, int *home_path)
{
	if (env->num_args == 1 && (*tmp = get_env("PWD", env)))
	{
		*tmp = get_env("PWD", env);
		*tmp = ft_strchr(*tmp, '=');
		*tmp += 1;
		*path = build_path(*tmp, env->args[0]);
		*home_path = 0;
	}
	else if (!(*path = get_env("HOME", env)))
	{
		ft_printf("cd: HOME variable not found\n");
		return (1);
	}
	return (0);
}

void	ft_cd(t_env *env)
{
	char	*path;
	char	*tmp;
	int		home_path;

	path = NULL;
	home_path = 1;
	if (env->num_args > 1)
		ft_printf("cd: Invalid number of arguments\n");
	else
	{
		if (cd_aux(&tmp, &path, env, &home_path) == 1)
			return ;
		if (home_path == 1)
		{
			path = ft_strchr(path, '=');
			path++;
		}
		change_path(path, env);
		change_env("PWD", getcwd(NULL, 0), env);
		if (path && home_path == 0)
			free(path);
	}
}
