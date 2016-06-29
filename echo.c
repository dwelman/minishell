/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 13:38:43 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/27 15:02:22 by daviwel          ###   ########.fr       */
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

void	print_arg(char *str)
{
	int	use_hidden;
	int	i;

	i = 0;
	use_hidden = str[i] == '"' ? 1 : 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			i++;
		if (str[i] == '\\' && use_hidden == 1)
		{
			handle_flag(str, &i);
		}
		else if (str[i] == '\\')
			i++;
		if (str[i] != '\0' && str[i] != '"')
			write(1, &str[i], 1);
		if (str[i] != '\0')
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
			print_arg(env->args[i]);
			ft_printf(" ");
			i++;
		}
		ft_printf("\n");
	}
}
