/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:24:34 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:29:52 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

int	ft_puissance(int nb, int puissance)
{
	int	res;

	res = nb;
	if (puissance == 0)
		return (1);
	while (puissance > 1)
	{
		res *= nb;
		puissance--;
	}
	return (res);
}
