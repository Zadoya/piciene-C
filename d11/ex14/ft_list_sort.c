/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:44:23 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/17 20:00:44 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sdtlib.h>
#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*a;
	t_list	*b;
	void	*tmp;

	a = *begin_list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if ((*cmp)(a->data, b->data) > 0)
			{
				tmp = b->data;
				b->data = a->data;
				a->data = b->data;
			}
			b = b->next;
		}
		a = a->next;
	}
}
