/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:55:43 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/29 15:42:33 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *var, t_env *env)
{
	int		i;
	char	*ret;

	i = find_line(var, env->env_var);
	ret = NULL;
	if (i == -1)
		return (NULL);
	else
		ret = ft_strdup(env->env_var[i]);
	return (ret);
}
