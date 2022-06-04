/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:29:06 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/02 19:17:43 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char *str)
{
	write(2, "minishell: export: '", 20);
	write(2, str, ft_strlen(str));
	write(2, "': not a valid identifier\n", 26);
	return (1);
}

int	ft_export(char **argv)
{
	if (!argv[1])
	{
		if (print_export() == -1)
			return (-1);
	}
	else
	{
		if (added_arg(&(argv[1])) == -1)
			return (-1);
	}
	return (1);
}
