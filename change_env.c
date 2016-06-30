/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:19:02 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 09:13:44 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_env(char *name, char *info, t_env *env)
{
	int	size;

	size = 0;
	size += ft_strlen(name) + ft_strlen(info) + 1;
	env->args = (char **)malloc(sizeof(char *) + 2);
	env->num_args = 1;
	env->args[0] = (char *)malloc(sizeof(char) * size + 1);
	env->args[0] = ft_strcat(env->args[0], name);
	env->args[0] = ft_strcat(env->args[0], "=");
	env->args[0] = ft_strcat(env->args[0], info);
	env->args[0] = ft_strcat(env->args[0], "\0");
	ft_setenv(env);
}
