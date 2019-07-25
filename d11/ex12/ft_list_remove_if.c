/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:58:15 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/17 18:59:02 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *elem;
	t_list *del;
	t_list *prev;

	elem = *begin_list;
	while (elem)
	{
		if ((*cmp)(elem->data, data_ref) == 0)
		{
			if (elem == *begin_list)
				*begin_list = elem->next;
			else
				prev->next = elem->next;
			del = elem;
			elem = elem->next;
			free(del);
		}
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}
