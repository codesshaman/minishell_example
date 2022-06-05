/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bj: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 08:32:43 bj mbonnet           #+#    #+#             */
/*   Updated: 2022/02/02 12:28:18 bj mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_key(char *env)
{
	int		i;
	char	*res;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (env[i] && env[i] != '=')
	{
		res[i] = env[i];
		i++;
	}
	res[i] = env[i];
	res[++i] = '\0';
	return (res);
}

char	*env_var(char *env)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	while (env[i + len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	len = 0;
	while (env[i + len])
	{
		res[len] = env[i + len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

int	init_struct_env(void)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (g_term.envp[j])
		j++;
	g_term.ft_env = malloc(sizeof(t_env) * (j + 1));
	if (!g_term.ft_env)
		return (-1);
	while (i < j)
	{
		g_term.ft_env[i].key = env_key(g_term.envp[i]);
		g_term.ft_env[i].var = env_var(g_term.envp[i]);
		if (!g_term.ft_env[i].var || !g_term.ft_env[i].key)
			return (-1);
		i++;
	}
	g_term.ft_env[i].key = NULL;
	g_term.ft_env[i].var = NULL;
	return (1);
}
