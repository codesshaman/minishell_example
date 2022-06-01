/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_tab_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:55 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:30:47 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

void	ft_free_double_tab_char(char **tab)
{
	int	x;

	x = -1;
	if (!tab)
		return ;
	while (tab[++x])
		free(tab[x]);
	free(tab[x]);
	free(tab);
}
