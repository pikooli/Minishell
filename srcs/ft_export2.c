/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:01:49 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/11 17:04:25 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_dup_export(char *str, int lenght, int i)
{
	char*dest;
	int quote;
	int dquote;

	quote = 1;
	dquote = 1;
	if (!(dest = malloc(lenght + 1)))
		return (0);
	while (i < lenght && *str)
	{
		if (*str == '\'' && dquote == 1)
		{
			quote *= -1;
			str++;
		}
		if (*str == '\"' && quote == 1)
		{
			str++;
			dquote *= -1;
		}
		dest[i++] = *str++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_lenght_to_export(char *str, char cara)
{
	int quote;
	int dquote;
	int i;

	dquote = 1;
	quote = 1;
	i = 0;
	while (str[i])
	{
		str[i] == '\'' && dquote == 1 ? quote *= -1 : 0;
		str[i] == '\"' && quote == 1 ? dquote *= -1 : 0;
		if (str[i] == cara && quote == 1 && dquote == 1)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_get_var(char *str, char **local)
{
	char*new_v;
	char*dest;
	int lenght;

	lenght = ft_strlen(str);
	if ((dest = ft_local(str, local)))
		return (dest);
	if (!(new_v = ft_dup_export(str, lenght, 0)))
		return (0);
	return (new_v);
}
