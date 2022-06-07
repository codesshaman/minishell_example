/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:44 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:27:57 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

int	ft_whitespace(char cara)
{
	if (cara == ' ' || cara == '\t' || cara == '\n'
		|| cara == '\v' || cara == '\r' || cara == '\f')
		return (1);
	return (0);
}