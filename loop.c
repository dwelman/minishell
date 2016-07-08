/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 09:05:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/08 15:24:47 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		only_ws(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (i == ft_strlen(line))
		return (1);
	return (0);
}

void	loop(t_env *env)
{
	char	*line;
	char	*ptr;

	env->done = 0;
	while (env->done == 0)
	{
		ft_printf("$> ");
		get_next_line(0, &line);
		while (ft_strlen(line) == 0 || only_ws(line))
		{
			free(line);
			ft_printf("$> ");
			get_next_line(0, &line);
		}
		ptr = line;
		while (*ptr == ' ' || *ptr == '\t')
			ptr++;
		get_commands(ptr, env);
		execute(env);
		free(line);
		if (env->num_args > 0)
			free(env->args);
	}
}
