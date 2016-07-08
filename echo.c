/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 13:38:43 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/08 11:48:08 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_flag(char *str, int *i)
{
	if (str[*i] == '\\' && str[*i + 1] == 't')
	{
		ft_printf("\t");
		*i += 2;
	}
	if (str[*i] == '\\' && str[*i + 1] == 'n')
	{
		ft_printf("\n");
		*i += 2;
	}
	else
		i++;
}

void	handle_env(char *str, int *i, t_env *env)
{
	int		j;
	char	*temp;
	char	*var;

	temp = ft_strdup(str);
	ft_strclr(temp);
	if (str[*i + 1] != '\0')
	{
		*i += 1;
		j = 0;
		while (str[*i] != '$' && str[*i] != '\0')
		{
			temp[j] = str[*i];
			*i += 1;
			j++;
		}
		var = get_env(temp, env);
		if (var != NULL)
		{
			var = ft_strchr(var, '=');
			var++;
			ft_printf("%s", var);
		}
	}
}

void	handle_quotes(char *str, int *i, int use_hidden)
{
	if (str[*i] == '"')
	{
		*i += 1;
		while (str[*i] && str[*i] != '"')
		{
			if (str[*i] == '\\' && use_hidden == 1)
				handle_flag(str, i);
			else if (str[*i] == '\\')
				*i += 1;
			if (str[*i] != '\0' && str[*i] != '"')
				write(1, &str[*i], 1);
			*i += 1;
		}
	}
}

void	print_arg(char *str, t_env *env)
{
	int		use_hidden;
	int		i;

	i = 0;
	use_hidden = str[i] == '"' ? 1 : 0;
	while (str[i] != '\0')
	{
		handle_quotes(str, &i, use_hidden);
		if (str[i] == '$')
			handle_env(str, &i, env);
		if (str[i] == '\\' && use_hidden == 1)
			handle_flag(str, &i);
		else if (str[i] == '\\')
			i++;
		if (str[i] == '$' && str[i + 1] == '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		else if (str[i] != '\0' && str[i] != '"' && str[i] != '$')
			write(1, &str[i], 1);
		if (str[i] != '\0' && str[i] != '$')
			i++;
	}
}

void	echo(t_env *env)
{
	int	i;

	i = 0;
	if (env->num_args == 0)
		ft_printf("\n");
	else
	{
		while (i < env->num_args)
		{
			print_arg(env->args[i], env);
			ft_printf(" ");
			i++;
		}
		ft_printf("\n");
	}
}
