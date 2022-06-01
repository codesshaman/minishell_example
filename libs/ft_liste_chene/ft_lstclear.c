/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleslee <jleslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:21:17 by mbonnet           #+#    #+#             */
/*   Updated: 2022/06/01 19:30:02 by jleslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (del)
	{
		while (*lst)
		{
			del((*lst)->content);
			tmp = *lst;
			(*lst) = tmp->next;
			free(tmp);
		}
		*lst = NULL;
	}
}
