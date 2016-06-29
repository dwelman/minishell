/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 09:05:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/28 13:38:02 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(t_env *env)
{
	char	*line;

	env->done = 0;
	while (env->done == 0)
	{
		ft_printf("$> ");
		get_next_line(0, &line);
		get_commands(line, env);
		execute(env);
		free(line);
		if (env->num_args > 0)
			free(env->args);
	}
}
