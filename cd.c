/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:03:18 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/29 15:47:33 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_env *env)
{
	char	*path;
	char	*old_pwd;
	char	*tmp;

	old_pwd = NULL;
	path = NULL;
	if (env->num_args > 1)
		ft_printf("cd: Invalid number of arguments\n");
	else
	{
		if (env->num_args == 1 && (tmp = get_env("PWD", env)))
		{
			tmp = get_env("PWD", env);
			ft_printf("HAI\n");
			tmp++;
			path = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 2);
			path = ft_strdup(tmp);
			path = ft_strcat(path, "/");
			path = ft_strcat(path, env->args[0]);
			path = ft_strcat(path, "\0");
		}
		else if (!(path = get_env("HOME", env)))
		{
			ft_printf("cd: HOME variable not found\n");
			return ;
		}
		path = ft_strchr(path, '=');
		path++;
		if (access(path, F_OK) != 0)
			ft_printf("cd: No such file or directory\n");
		if (access(path, R_OK) != 0)
			ft_printf("cd: Permission denied\n");
		if (chdir(path) != 0)
			ft_printf("cd: Not a directory\n");
		old_pwd = env->env_var[find_line("PWD", env->env_var)];
		old_pwd = ft_strchr(old_pwd, '=');
		old_pwd++;
		change_env("OLDPWD", old_pwd, env);
		change_env("PWD", getcwd(NULL, 0), env);
		/*if (path)
			free(path);*/
	}
}
