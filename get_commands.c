/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 09:46:06 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/27 12:41:45 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_words(char *line)
{
	int	ret;
	int	substr;
	int	quote;

	ret = 0;
	substr = 0;
	quote = 0;
	if (line != NULL)
		while (*line != '\0')
		{
			if (*line == '"' && quote == 0)
				quote = 1;
			else if (*line == '"' && quote == 1)
			{
				quote = 0;
				substr = 1;
				ret++;
			}
			else if (substr == 0 && *line != ' ' && quote == 0 && *line != '\0')
			{
				substr = 1;
				ret++;
			}
			if (*line == ' ' && quote == 0 && substr == 1)
				substr = 0;
			line++;
		}
	return (ret - 1);
}

int		wordlen(char *line)
{
	int	len;
	int	quote;

	len = 0;
	quote = 0;
	while (*line != '\0' && *line != ' ')
	{
		if (*line == '"')
		{
			line++;
			len++;
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

void	args(char *line, t_env *env)
{
	char	*str;
	int		words;
	int		i;
	int		j;
	int		k;

	str = ft_strchr(line, ' ');
	words = count_words(line);
	i = 0;
	env->num_args = words;
	str++;
	if (env->num_args > 0)
	{
		env->args = (char **)malloc(sizeof(char *) * env->num_args + 1);
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

	i = 0;
	command(line, env);
	args(line, env);
}
