/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 08:50:29 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/30 15:32:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

typedef struct	s_env
{
	int			done;
	int			num_args;
	char		**argv;
	char		*com;
	char		**args;
	char		**env_var;
}				t_env;

int				count_words(char *line);

void			args(char *line, t_env *env);

int				wordlen(char *line);

char			*build_path(char *tmp, char *add);

void			ft_run(t_env *env);

void			ft_pwd(t_env *env);

void			ft_cd(t_env *env);

void			change_env(char *name, char *info, t_env *env);

char			*get_env(char *var, t_env *env);

void			ft_unsetenv(t_env *env);

int				find_line(char *var_name, char **arr);

char			**copy_env(char **env);

void			ft_setenv(t_env *env);

void			free_arr(char **arr);

void			loop(t_env *env);

void			get_commands(char *line, t_env *env);

void			execute(t_env *env);

void			echo(t_env *env);

void			show_env(char **str);

#endif
