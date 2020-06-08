/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:54:44 by paszhang          #+#    #+#             */
/*   Updated: 2020/01/11 17:04:20 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cmp_envp(char **envp, char *new)
{
	int i;

	i = -1;
	while (envp[++i])
		if (ft_cmp_to_cara(envp[i], new, '='))
		{
			if (new[ft_strlen(new) - 1] == '=')
			{
				free(new);
				return (1);
			}
			free(envp[i]);
			envp[i] = new;
			return (1);
		}
	return (0);
}

char	**ft_new_envp(char **envp, char *new)
{
	char**new_env;
	int i;

	if (ft_cmp_envp(envp, new))
		return (envp);
	i = 0;
	while (envp[i])
		i++;
	if (!(new_env = malloc(sizeof(char *) * (i + 3))))
		return (0);
	i = -1;
	while (envp[++i])
		new_env[i] = envp[i];
	new_env[i++] = new;
	new_env[i] = NULL;
	free(envp);
	return (new_env);
}

int		ft_export2(char *str, t_env *env)
{
	char*new_v;

	if (!(ft_strneedel(str, "=")))
	{
		str = ft_join(str, "=");
		if (!(new_v = ft_get_var(str, env->local)))
			return (1);
		free(str);
	}
	else
	{
		if (!(new_v = ft_get_var(str, env->local)))
			return (1);
	}
	if (!(env->envp = ft_new_envp(env->envp, new_v)))
		return (1);
	return (0);
}

int		ft_isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		ft_export(char *str, t_env *env)
{
	int i;
	char**new;

	g_dollar = 0;
	i = ft_echo_position(str);
	i += ft_jump_space(&str[i]);
	if (str[i] == '\0')
		return (ft_invalidcmd(str, 4, env));
	if (!(new = ft_split(&str[i], ' ')))
		return (0);
	i = 0;
	while (new[i])
	{
		if (ft_isalpha(new[i][0]) == 0)
			ft_invalidcmd(new[i++], 6, env);
		if (new[i])
			if (ft_export2(new[i++], env))
			{
				ft_free_2d(new);
				return (0);
			}
	}
	ft_free_2d(new);
	return (1);
}
