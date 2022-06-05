/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:17:25 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/05 19:39:22 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	my_check_nb_guillemet(char *str)
{
	int	x;
	int	gu;

	x = 0;
	gu = 0;
	while (str[x])
	{
		if (gu == 0 && str[x] == '\'')
			gu = 1;
		else if (gu == 0 && str[x] == '\"')
			gu = 2;
		else if (gu == 1 && str[x] == '\'')
			gu = 0;
		else if (gu == 2 && str[x] == '\"')
			gu = 0;
		x++;
	}
	return (gu);
}

int	my_check_bad_red(char *str)
{
	int	x;
	int	gu;
	int	tem;

	x = 0;
	gu = 0;
	tem = 0;
	while (str[x])
	{
		check_quote(&gu, str[x]);
		if (check_redirect(gu, str[x]) < 0)
			tem++;
		else
			tem = 0;
		if (tem == 3)
			return (-1);
		x++;
	}
	return (1);
}
