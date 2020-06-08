/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:11:08 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/12 15:20:35 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_remove_quote_cd(char *dest)
{
	int		i;
	int		s;
	t_cmd	cmd;

	cmd.quote = 1;
	cmd.dquote = 1;
	s = 0;
	i = -1;
	while (dest[++i])
	{
		if (dest[i] == '\'' && cmd.dquote == 1)
		{
			cmd.quote *= -1;
			i++;
		}
		else if (dest[i] == '\'' && cmd.quote == 1)
		{
			cmd.dquote *= -1;
			i++;
		}
		dest[s] = dest[i];
		s++;
	}
	dest[s] = '\0';
}
