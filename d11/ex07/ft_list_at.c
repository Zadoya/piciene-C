/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:20:13 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/17 15:31:54 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*elem;
	int		i;

	elem = begin_list;
	i = 0;
	while (i != nbr)
	{
		if (elem->next == NULL)
			return (NULL);
		elem = elem->next;
		i++;
	}
	return (elem);
}
