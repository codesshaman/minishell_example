/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:55 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:30:45 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

void	*ft_calloc(size_t nb, size_t len_nb)
{
	void	*res;

	res = (void *)malloc(len_nb * nb);
	if (!(res))
		return (NULL);
	ft_bzero(res, nb * len_nb);
	return (res);
}
