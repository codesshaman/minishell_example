/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_var_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:53:40 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/05 20:49:30 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg_var_env(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
	{
		check_var_env(&(str[i]));
		cleaning_quotes(&(str[i]));
	}
	return (1);
}

int	check_redirect_var_env(t_intra_red *str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i].red)
	{
		if (ft_strncmp(str[i].red, "<<", 3) == 0)
			continue ;
		check_var_env(&(str[i].red));
		check_var_env(&(str[i].file));
		cleaning_quotes(&(str[i].red));
		cleaning_quotes(&(str[i].file));
	}
	return (1);
}

int	control_var_env_quotes(t_cmd *cmd)
{
	if (cmd->cmd)
	{
		check_var_env(&cmd->cmd);
		cleaning_quotes(&cmd->cmd);
	}
	if (!cmd->path)
	{
		cmd->path = free_tab((void **)&(cmd->path));
		cmd->path = recup_path(&cmd->cmd);
		cleaning_quotes(&cmd->path);
	}
	if (cmd->arg)
		check_arg_var_env(cmd->arg);
	if (cmd->red)
		check_redirect_var_env(cmd->red);
	return (1);
}
