/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:01:20 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/04 20:31:58 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_tab(void **a_free)
{
	if (*a_free)
		free(*a_free);
	*a_free = NULL;
	return (NULL);
}

void	*my_free_double_tab(void **tab_str, int nb_str)
{
	int	op;

	if (!tab_str)
		return (NULL);
	if (nb_str != -1)
		op = -1;
	else
	{
		nb_str = 0;
		op = 1;
	}
	while (nb_str >= 0 && tab_str[nb_str])
	{
		if (tab_str[nb_str])
			tab_str[nb_str] = free_tab((void **)&(tab_str[nb_str]));
		else
			break ;
		nb_str += (1 * op);
	}
	tab_str = free_tab((void **)&tab_str);
	return (NULL);
}

void	*listing(t_cmd *cmd)
{
	int			i;
	int			x;
	t_cmd		*tmp;

	x = 0;
	i = 1;
	g_term.str_cmd = free_tab((void **)&(g_term.str_cmd));
	if (!cmd)
		return (NULL);
	i = g_term.nb_maillon;
	while (i > 0)
	{
		tmp = cmd->next;
		cmd = my_free_maillon(cmd);
		if (tmp == NULL)
			break ;
		i--;
		cmd = tmp;
	}
	g_term.nb_maillon = 0;
	g_term.cmd = NULL;
	return (NULL);
}

void	*my_free_intra_red(t_intra_red **red)
{
	int	x;

	x = -1;
	while ((*red) && (*red)[++x].red)
	{
		(*red)[x].fichier = free_tab((void **)&((*red)[x].fichier));
		(*red)[x].red = free_tab((void **)&((*red)[x].red));
	}
	*red = free_tab((void **)&((*red)));
	return (NULL);
}

void	*my_free_maillon(t_cmd *tmp)
{
	int	x;

	x = -1;
	if (tmp == NULL)
		return (NULL);
	tmp->cmd = free_tab((void **)&(tmp->cmd));
	tmp->path = free_tab((void **)&(tmp->path));
	tmp->red = my_free_intra_red(&(tmp->red));
	while (tmp->arg && tmp->arg[++x])
		tmp->arg[x] = free_tab((void **)&(tmp->arg[x]));
	tmp->arg = free_tab((void **)&(tmp->arg));
	tmp->pip = free_tab((void **)&(tmp->pip));
	tmp = free_tab((void **)&tmp);
	return (NULL);
}
