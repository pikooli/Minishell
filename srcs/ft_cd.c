/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:40:58 by paszhang          #+#    #+#             */
/*   Updated: 2020/01/13 14:05:33 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_go_home(char **envp)
{
	char *home;

	if (!(home = ft_found_path(envp, "HOME")))
		return (0);
	chdir(home);
	return (0);
}

char	*ft_change_vague(char *str)
{
	char	*dest;
	int		ret;

	if (!(dest = ft_join(g_home, str + 1)))
		return (0);
	ret = chdir(dest);
	free(dest);
	ret == -1 ? ft_cd_error(str, 0) : 0;
	return (dest);
}

char	*ft_cd_2(char *str, t_env *env)
{
	char	*dest;

	dest = str;
	if (*dest == '\0' || (*dest == '~' && *(dest + 1) == '\0'))
	{
		ft_go_home(env->envp);
		return (0);
	}
	if ((*dest == '\'' || *dest == '\"') && *(dest + 1) == '~')
		return (dest);
	if (*str == '\'')
		if (!(dest = ft_strtrim(ft_strdup(str), "\'")))
			return (0);
	if (*str == '\"')
		if (!(dest = ft_strtrim(ft_strdup(str), "\"")))
			return (0);
	return (dest);
}

int		ft_cd(char *str, t_env *env)
{
	int ret;
	char*dest;
	int i;

	str += ft_echo_position(str);
	str += ft_jump_space(str);
	if (!(dest = ft_cd_2(str, env)))
		return (0);
	i = dest != str ? 1 : 0;
	if (*dest == '~')
	{
		if (!(dest = ft_change_vague(dest)))
			return (0);
	}
	else
	{
		ft_remove_quote_cd(dest);
		ret = chdir(dest);
		ret == -1 ? ft_cd_error(str, 0) : 0;
		if (i == 1)
			free(dest);
	}
	return (0);
}
