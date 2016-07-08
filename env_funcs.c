/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 07:57:02 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/01 10:14:59 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_line(char *var_name, char **arr)
{
	int	i;
	int	len;

	i = 0;
	while (arr[i])
	{
		len = 0;
		while (arr[i][len] != '=')
			len++;
		if (ft_strstr(arr[i], var_name) != NULL)
		{
			if (ft_strncmp(arr[i], var_name, len) == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

void	unset_loop(t_env *env, int k, char **tmp)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (tmp[i])
		i++;
	len = i;
	env->env_var = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	j = 0;
	if (k != -1)
	{
		while (tmp[j] && i < len)
		{
			if (i == k)
				j++;
			if (tmp[j] != NULL && i < len)
				env->env_var[i] = ft_strdup(tmp[j]);
			i++;
			j++;
		}
		if (i < len)
			env->env_var[i] = NULL;
	}
}

void	ft_unsetenv(t_env *env)
{
	int		k;
	char	**tmp;
	char	*var;

	if (env->num_args != 1)
		ft_printf("Usage: unsetenv [VAR]\n");
	else
	{
		tmp = copy_env(env->env_var);
		var = env->args[0];
		if ((k = find_line(var, tmp)) == -1)
			ft_printf("Variable %s not found\n", var);
		else
			unset_loop(env, k, tmp);
		if (tmp)
			free_arr(tmp);
	}
}

void	set_loop(t_env *env, int k, char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (i == k)
			env->env_var[i] = ft_strdup(env->args[0]);
		else
			env->env_var[i] = ft_strdup(tmp[i]);
		i++;
	}
	if (k == -1)
	{
		env->env_var[i] = ft_strdup(env->args[0]);
		i++;
	}
	env->env_var[i] = NULL;
	if (tmp)
		free_arr(tmp);
}

void	ft_setenv(t_env *env)
{
	int		i;
	int		k;
	char	**tmp;
	char	**args;

	i = 0;
	if (env->num_args != 1)
		ft_printf("Usage: setenv [VAR=data]\n");
	else if (ft_strstr(env->args[0], "=") == NULL)
		ft_printf("Usage: setenv [VAR=data]\n");
	else
	{
		args = ft_strsplit(env->args[0], '=');
		tmp = copy_env(env->env_var);
		free_arr(env->env_var);
		while (tmp[i])
			i++;
		if ((k = find_line(args[0], tmp)) == -1)
			env->env_var = (char **)malloc(sizeof(char *) * (i + 2));
		else
			env->env_var = (char **)malloc(sizeof(char *) * (i + 1));
		set_loop(env, k, tmp);
		if (args)
			free_arr(args);
	}
}
