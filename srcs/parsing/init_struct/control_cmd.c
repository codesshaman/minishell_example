/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:50:53 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/05 20:51:30 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*recup_cmd(char **str)
{
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	while ((*str)[++i])
	{
		if (ft_whitespace((*str)[i]) == 1)
			continue ;
		res = recup_ellement(str, &i);
		break ;
	}
	return (res);
}

char	*recup_path(char **str)
{
	char	*res;
	char	*tmp;
	int		len;
	char	c;

	res = NULL;
	len = ft_strlen(*str);
	while (--len >= 0)
		if ((*str)[len] == '/')
			break ;
	if (len >= 0)
	{
		c = (*str)[len + 1];
		(*str)[len + 1] = '\0';
		res = ft_strdup(*str);
		(*str)[len + 1] = c;
		tmp = ft_strdup(&((*str)[len + 1]));
		(*str) = free_tab((void **)str);
		(*str) = tmp;
	}
	return (res);
}

char	**recup_path_env_2(void)
{
	char	**path;
	int		i;

	i = 0;
	if (!g_term.ft_env)
		return (NULL);
	while (g_term.ft_env[i].key)
	{
		if (ft_strncmp(g_term.ft_env[i].key,
				"PATH=", ft_strlen(g_term.ft_env[i].key)) == 0)
		{
			path = ft_split(g_term.ft_env[i].var, ':');
			break ;
		}
		i++;
	}
	if (!g_term.ft_env[i].key)
		return (NULL);
	return (path);
}

char	*recup_path_env(char *cmd)
{
	char	**path;
	char	*tmp_2;
	char	*tmp;
	int		i;

	tmp = NULL;
	path = recup_path_env_2();
	i = -1;
	while (cmd && path && path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp_2 = ft_strjoin(tmp, cmd);
		if (access(tmp_2, F_OK) == 0)
		{
			tmp_2 = free_tab((void **)&tmp_2);
			break ;
		}
		tmp = free_tab((void **)&tmp);
		tmp_2 = free_tab((void **)&tmp_2);
	}
	path = free_double_tab((void **)path, -1);
	return (tmp);
}
