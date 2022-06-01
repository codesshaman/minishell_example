/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:34 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:30:37 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

int	get_next_line_2(char **lines, char *buf, int end_buff)
{
	char			*line_tmp;

	if (end_buff <= 0)
		return (-1);
	buf[end_buff] = '\0';
	line_tmp = *lines;
	*lines = ft_strjoin(line_tmp, buf);
	free(line_tmp);
	return (1);
}

int	get_next_line_3(char **lines)
{
	if (*lines == NULL)
	{
		*lines = ft_alloc(0);
		if (*lines == NULL)
			return (-1);
	}
	return (1);
}
