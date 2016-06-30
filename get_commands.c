/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 09:46:06 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 14:36:55 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	word_loop(int *ret, char *line)
{
	int	quote;
	int	substr;

	quote = 0;
	substr = 0;
	while (*line != '\0')
	{
		if (*line == '"' && quote == 0)
			quote = 1;
		else if (*line == '"' && quote == 1)
		{
			quote = 0;
			substr = 1;
			*ret += 1;
		}
		else if (substr == 0 && *line != ' ' && quote == 0 && *line != '\0')
		{
			substr = 1;
			*ret += 1;
		}
		if (*line == ' ' && quote == 0 && substr == 1)
			substr = 0;
		line++;
	}
}

int		count_words(char *line)
{
	int	ret;

	ret = 0;
	if (line != NULL)
		word_loop(&ret, line);
	return (ret - 1);
}

int		wordlen(char *line)
{
	int	len;

	len = 0;
	while (*line != '\0' && *line != ' ')
	{
		if (*line == '"')
		{
			line++;
			while (*line != '"' && *line != '\0')
			{
				line++;
				len++;
			}
			line++;
			len++;
			break ;
		}
		else
		{
			len++;
			line++;
		}
	}
	return (len);
}

void	command(char *line, t_env *env)
{
	int	j;

	j = 0;
	while (line[j] != ' ' && line[j] != '\0')
		j++;
	env->com = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (line[j] != ' ' && line[j] != '\0')
	{
		env->com[j] = line[j];
		j++;
	}
	env->com[j] = '\0';
}

void	get_commands(char *line, t_env *env)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (env->argv != NULL)
		free_arr(env->argv);
	command(line, env);
	args(line, env);
	env->argv = (char **)malloc(sizeof(char *) * (env->num_args + 2));
	env->argv[k] = ft_strdup(env->com);
	k++;
	while (i < env->num_args)
	{
		env->argv[k] = ft_strdup(env->args[i]);
		i++;
		k++;
	}
	env->argv[k] = NULL;
}
