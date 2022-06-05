/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:24:57 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/02 18:55:35 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_space_2(void)
{
	int	i;

	i = 0;
	while (ft_whitespace(g_term.str_cmd[i]) == 1)
		i++;
	if (!g_term.str_cmd[i])
		return (-1);
	return (1);
}

int	init_parsing_2(void)
{
	int	quote;

	quote = check_nb_quotes(g_term.str_cmd);
	if (quote != 0)
	{
		g_term.str_cmd = free_tab((void **)&(g_term.str_cmd));
		if (quote == 2)
			g_term.str_cmd = ft_strdup("<<\"");
		else if (quote == 1)
			g_term.str_cmd = ft_strdup("<<\'");
	}
	if (check_bad_redirect(g_term.str_cmd) == -1)
		return (-1);
	return (0);
}

int	init_parsing(void)
{
	char	**tab_cmd;

	tab_cmd = NULL;
	if (check_space_2() == -1)
		return (2);
	if (init_parsing_2() == -1)
		return (-1);
	tab_cmd = init_tab_cmd(g_term.str_cmd);
	if (!tab_cmd)
	{
		tab_cmd = free_double_tab((void **)tab_cmd, -1);
		return (3);
	}
	if (create_cmd(tab_cmd) == -1)
	{
		printf(ROUGE"Memory allocation error\n"BLANC);
		tab_cmd = free_double_tab((void **)tab_cmd, -1);
		return (-2);
	}
	tab_cmd = free_double_tab((void **)tab_cmd, -1);
	return (0);
}
