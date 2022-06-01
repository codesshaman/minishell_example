/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:43:57 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:30:57 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

void	ft_putnbr_fd(int n, int fb)
{
	if (n == MIN)
	{
		ft_putstr_fd("-2147483648", fb);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fb);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fb);
	}
	ft_putchar_fd(n % 10 + '0', fb);
}
