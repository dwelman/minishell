/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 08:26:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 09:09:39 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_env *env)
{
	char	*path;

	path = get_env("PWD", env);
	if (path != NULL)
	{
		path = ft_strchr(path, '=');
		path++;
		ft_printf("%s\n", path);
	}
	else
		ft_printf("PWD not found\n");
}
