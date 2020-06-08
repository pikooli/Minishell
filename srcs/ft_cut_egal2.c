/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_egal2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:51:03 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/11 16:59:56 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_local_add(char *str, t_env *env)
{
	env->local = ft_new_envp(env->local, str);
}

void	ft_addexport(char *str, t_env *env)
{
	if (!ft_cmp_envp(env->envp, str))
		free(str);
}

char	**ft_remove(char *str)
{
	char **dest;

	dest = ft_split(str + 1, '\0');
	return (dest);
}
