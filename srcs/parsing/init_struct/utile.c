/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:47:47 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:17:45 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirect_pipe(char *str)
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

char	*take_redirect(int choose, int *i, char **str)
{
	if (choose > 2 && choose < 7)
	{
		(*str)[(*i)++] = ' ';
		(*str)[(*i)++] = ' ';
	}
	else
		(*str)[(*i)++] = ' ';
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

char	*return_ellement(char **str, int *i)
{
	char	*new;
	int		gu;
	int		j;

	j = 0;
	gu = 0;
	new = NULL;
	while (ft_whitespace((*str)[*i]) == 1)
		(*i)++;
	while ((*str)[*i + j])
	{
		check_quote(&gu, (*str)[*i + j]);
		if (!(*str)[*i + j] || (gu == 0 && (ft_whitespace((*str)[*i + j]) == 1
			|| check_redirect_pipe(&(*str)[*i + j]) > 0)))
			return (new);
		else
		{
			new = ft_strmicrojoin(&new, (*str)[*i + j]);
			(*str)[*i + j] = ' ';
		}
		(*i)++;
	}
	return (new);
}
