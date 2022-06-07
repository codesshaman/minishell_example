/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:50:35 by jleslee           #+#    #+#             */
/*   Updated: 2022/06/07 20:20:07 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_term	g_term;

int	free_all(int ret)
{
	int	x;

	x = 0;
	while (g_term.ft_env && g_term.ft_env[x].key != NULL)
	{
		g_term.ft_env[x].key = free_tab((void **)&(g_term.ft_env[x].key));
		g_term.ft_env[x].var = free_tab((void **)&(g_term.ft_env[x].var));
		x++;
	}
	rl_clear_history();
	if (g_term.ft_env)
		g_term.ft_env = free_tab((void **)&(g_term.ft_env));
	return (ret);
}

int	launch_setup(int ac, char **envp)
{
	if (ac != 1)
		return (-1);
	start_write();
	signal(SIGINT, handler_ctr_c);
	signal(SIGQUIT, SIG_IGN);
	g_term.envp = envp;
	g_term.ft_env = NULL;
	if (init_struct_env() == -1)
		return (-1);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	(void)av;
	if (launch_setup(ac, envp) == -1)
		return (-1);
	while (1)
	{
		g_term.str_cmd = NULL;
		g_term.str_cmd = readline(BLU_2"shell-3.2$ "RESET);
		if (g_term.str_cmd == 0)
		{
			free(g_term.str_cmd);
			rl_clear_history();
			return (free_all(-1));
		}
		if (g_term.str_cmd[0])
		{
			add_history(g_term.str_cmd);
			if (launch() == -1)
				return (free_all(-1));
		}
		else
			free(g_term.str_cmd);
	}
	return (free_all(0));
}
