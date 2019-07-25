/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:59:50 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/17 19:26:01 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <sdtlib.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *elem;

	elem = *begin_list1;
	if (elem)
	{
		while (elem->next)
			elem = elem->next;
		elem->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
