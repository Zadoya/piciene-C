/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:53:16 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/17 20:14:18 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list *rev;
	t_list *elem;
	t_list *tmp;

	elem = *begin_list;
	rev = elem;
	elem = elem->next;
	rev->next = NULL;
	while (elem)
	{
		tmp = rev;
		rev = elem;
		elem = elem->next;
		rev->next = tmp;
	}
	*begin_list = rev;
}
