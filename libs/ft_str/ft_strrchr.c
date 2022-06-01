/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:46:22 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:29:20 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*res;

	res = (0);
	while (*str)
	{
		if (*str == c)
			res = (char *)str;
		str++;
	}
	if (res)
		return (res);
	if (c == '\0')
		return ((char *)str);
	return (0);
}
