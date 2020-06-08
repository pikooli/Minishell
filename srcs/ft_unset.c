/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:01:58 by paszhang          #+#    #+#             */
/*   Updated: 2020/01/12 13:27:46 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cmp_unset(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if ((str1[i] == '=' || str1[i] == '\0') && str2[i] == '\0')
		return (1);
	return (0);
}

void	ft_swap(char **envp)
{
	int i;

	i = 0;
	while (envp[i + 1])
	{
		envp[i] = envp[i + 1];
		i++;
	}
	envp[i] = envp[i + 1];
}

void	ft_unset_p(char *str, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_cmp_unset(envp[i], str))
		{
			free(envp[i]);
			ft_swap(&envp[i]);
			break ;
		}
		i++;
	}
}

int		ft_unset(char *str, t_env *env)
{
	int		i;
	char	**array;

	i = 0;
	array = ft_split(str, ' ');
	str += ft_echo_position(str);
	while (array[i])
	{
		while (*array[i] == ' ')
			array[i]++;
		ft_unset_p(array[i], env->local);
		ft_unset_p(array[i], env->envp);
		i++;
	}
	ft_free_2d(array);
	return (0);
}
