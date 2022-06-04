/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_red.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:35:30 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/04 19:54:15 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	overwrite_file(char *fichier)
{
	int		fd;

	fd = open(fichier, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		if (remove(fichier) != 0)
			return (-1);
	}
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		fd = open(fichier, O_CREAT);
	else
		close(fd);
	return (1);
}

int	my_recup_fd(char *fichier, int x)
{
	int		fd;
	char	c;

	fd = -1;
	if (ft_strncmp(g_term.cmd->red[x].red, ">", 3) == 0)
		overwrite_file(fichier);
	fd = open(fichier, O_RDWR);
	if (fd == -1 && ft_strncmp(g_term.cmd->red[x].red, "<", 3) != 0)
	{
		close(fd);
		fd = open(fichier, O_CREAT);
		if (fd == -1)
			return (-1);
	}
	close(fd);
	fd = open(fichier, O_RDWR);
	if (fd == -1)
		return (-1);
	if (ft_strncmp(g_term.cmd->red[x].red, ">>", 3) == 0)
		while (read(fd, &c, 1) > 0)
			c = 'a';
	return (fd);
}

int	my_connect_red(void)
{
	int		x;
	int		fd;

	x = -1;
	fd = 0;
	while (g_term.cmd->red && g_term.cmd->red[++x].red)
	{
		if (ft_strncmp(g_term.cmd->red[x].red, "<<", 3) == 0)
			continue ;
		fd = my_recup_fd(g_term.cmd->red[x].fichier, x);
		if (ft_strncmp(g_term.cmd->red[x].red, ">", 3) == 0
			|| ft_strncmp(g_term.cmd->red[x].red, ">>", 3) == 0)
			dup2(fd, 1);
		else if (ft_strncmp(g_term.cmd->red[x].red, "<", 3) == 0)
		{
			if (fd == -1)
				printf(ROUGE"No such file or directory\n"BLANC);
			if (fd == -1)
				exit (1);
			dup2(fd, 0);
		}
		if (fd != -1)
			close(fd);
	}
	return (1);
}
