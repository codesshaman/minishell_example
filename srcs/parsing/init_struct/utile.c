/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:47:47 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/05 20:51:42 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirect_pip(char *str)
{
	if (str[0] == '&' && str[1] == '&')
		return (3);
	else if (str[0] == '|' && str[1] == '|')
		return (4);
	else if (str[0] == '>' && str[1] == '>')
		return (5);
	else if (str[0] == '<' && str[1] == '<')
		return (6);
	else if (str[0] == '|')
		return (1);
	else if (str[0] == ';')
		return (2);
	else if (str[0] == '>')
		return (7);
	else if (str[0] == '<')
		return (8);
	return (0);
}

char	*take_red(int choose, int *x, char **str)
{
	if (choose > 2 && choose < 7)
	{
		(*str)[(*x)++] = ' ';
		(*str)[(*x)++] = ' ';
	}
	else
		(*str)[(*x)++] = ' ';
	if (choose == 1)
		return (ft_strdup("|"));
	else if (choose == 2)
		return (ft_strdup(";"));
	else if (choose == 3)
		return (ft_strdup("&&"));
	else if (choose == 4)
		return (ft_strdup("||"));
	else if (choose == 5)
		return (ft_strdup(">>"));
	else if (choose == 6)
		return (ft_strdup("<<"));
	else if (choose == 7)
		return (ft_strdup(">"));
	else if (choose == 8)
		return (ft_strdup("<"));
	return (0);
}

char	*recup_ellement(char **str, int *x)
{
	char	*new;
	int		gu;
	int		i;

	i = 0;
	gu = 0;
	new = NULL;
	while (ft_whitespace((*str)[*x]) == 1)
		(*x)++;
	while ((*str)[*x + i])
	{
		check_quote(&gu, (*str)[*x + i]);
		if (!(*str)[*x + i] || (gu == 0 && (ft_whitespace((*str)[*x + i]) == 1
			|| check_redirect_pip(&(*str)[*x + i]) > 0)))
			return (new);
		else
		{
			new = ft_strmicrojoin(&new, (*str)[*x + i]);
			(*str)[*x + i] = ' ';
		}
		(*x)++;
	}
	return (new);
}
