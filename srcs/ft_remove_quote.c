/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:28:49 by paszhang          #+#    #+#             */
/*   Updated: 2020/01/12 11:16:02 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_quote(char *str, char cara)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == cara)
		{
			str[i] = '\0';
			return (ft_strdup(str));
		}
	}
	return (str);
}

char	*ft_redi_quote(char *str)
{
	int i;
	char*save;

	if (str == NULL)
		return (str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			save = ft_remove_quote(&str[i + 1], str[i]);
			free(str);
			return (save);
		}
	}
	return (str);
}
