/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:03:18 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/28 15:22:06 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err_msg(t_env *env, int code)
{
	if (code == 0)
		ft_printf("cd: Invalid number of arguments\n");
}

void	ft_cd(t_env *env)
{
	char	*path;
	int		i;

	if (!env->num_args != 1)
		err_msg(env, 0);
	else
	{
		if (env->args[0] != NULL)
			path = env->args[0];
		if (env->args[0] == NULL)
	}
}
