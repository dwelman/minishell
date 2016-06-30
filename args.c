/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:35:48 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 15:13:26 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arg_loop(t_env *env, int words, char *str, char *line)
{
	int	j;
	int	k;
	int	i;

	i = 0;
	while (words != 0)
	{
		while (*str == ' ' && *line != '\0')
			str++;
		j = wordlen(str);
		env->args[i] = (char *)malloc(sizeof(char) * j + 1);
		k = 0;
		while (k < j)
		{
			env->args[i][k] = *str;
			str++;
			k++;
		}
		env->args[i][k] = '\0';
		words--;
		i++;
	}
	env->args[i] = NULL;
}

void	args(char *line, t_env *env)
{
	char	*str;
	int		words;

	str = ft_strchr(line, ' ');
	words = count_words(line);
	env->num_args = words;
	str++;
	if (env->num_args > 0)
	{
		env->args = (char **)malloc(sizeof(char *) * env->num_args + 1);
		arg_loop(env, words, str, line);
	}
}
