/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:24:41 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/05 19:23:57 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipe(t_cmd *cmd)
{
	close(cmd->tub[ENTRE]);
	close(cmd->tub[SORTI]);
}

void	connect_pipe(void)
{
	if (ft_strncmp(g_term.cmd->pip, "|", 3) == 0)
	{
		close(g_term.cmd->tub[SORTI]);
		dup2(g_term.cmd->tub[ENTRE], 1);
		close(g_term.cmd->tub[ENTRE]);
	}
	else
	{
		ft_close_pipe(g_term.cmd);
	}
	if (ft_strncmp(g_term.cmd->prev->pip, "|", 3) == 0)
	{
		close(g_term.cmd->prev->tub[ENTRE]);
		dup2(g_term.cmd->prev->tub[SORTI], 0);
		close(g_term.cmd->prev->tub[SORTI]);
	}
}

void	close_pipe(void)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = g_term.cmd;
	while (i++ < g_term.nb_maillon)
	{
		ft_close_pipe(g_term.cmd);
		g_term.cmd = g_term.cmd->next;
	}
	g_term.cmd = tmp;
}

void	creat_pipe(void)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = g_term.cmd;
	while (i++ < g_term.nb_maillon)
	{
		pipe(g_term.cmd->tub);
		g_term.cmd = g_term.cmd->next;
	}
	g_term.cmd = tmp;
}