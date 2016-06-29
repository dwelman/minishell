/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 08:52:02 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/28 15:20:44 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **env)
{
	char	**tmp;
	int		i;

	i = 0;
	while (env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		tmp[i] = ft_strdup(env[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
		while (arr[i])
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
	if (arr)
		free(arr);
}

int		main(int argc, char **argv, char **environ)
{
	t_env	env;

	if (argc > 1)
		ft_printf("Unused variable: %s\n", argv[1]);
	env.env_var = copy_env(environ);
	loop(&env);
	if (env.env_var)
		free_arr(env.env_var);
	return (0);
}
