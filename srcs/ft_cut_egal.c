/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_egal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 12:27:32 by paszhang          #+#    #+#             */
/*   Updated: 2020/01/11 16:59:51 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_egal(char *str)
{
	char**dest;
	int i;

	if (!(dest = malloc(sizeof(char *) * 2)))
		return (0);
	if (!(dest[0] = ft_dup_to_space(str)))
		return (0);
	i = ft_lenght_to_cara(str, ' ');
	i += ft_jump_space(&str[i]);
	if (!(dest[1] = ft_strdup(&str[i])))
		return (0);
	return (dest);
}

char	**ft_egal(char *str, int *ret)
{
	int i;
	int quote;
	int dquote;

	quote = 1;
	dquote = 1;
	str += ft_jump_space(str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == ' ')
			break ;
		if (str[i] == '=')
		{
			*ret = 1;
			if (i == 0)
				return (ft_remove(str));
			*ret = 0;
			return (ft_split_egal(str));
		}
	}
	*ret = 1;
	return (ft_split(str, '\0'));
}

char	*ft_cut_egal(char *str, t_env *env)
{
	char**src;
	char*save;
	int ret;
	char*tmp;

	if (!(src = ft_egal(str, &ret)))
		return (0);
	if (ret == 0)
	{
		if (!(tmp = ft_strdup(src[0])))
			return (0);
		ft_addexport(tmp, env);
		ft_local_add(src[0], env);
		save = src[1];
		free(src);
		return (save);
	}
	save = src[0];
	free(src);
	return (save);
}
