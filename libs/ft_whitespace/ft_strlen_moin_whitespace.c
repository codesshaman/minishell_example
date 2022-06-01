/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_moin_whitespace.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:44 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:27:55 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

int	ft_strlen_moin_whitespace(char *str)
{
	int	x;
	int	y;

	y = 0;
	x = -1;
	while (str[++x])
		if (ft_whitespace(str[x]) == 0)
			y++;
	return (y);
}
