/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:48:57 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/17 15:08:50 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*elem;
	t_list	*tmp;
	int		i;

	i = 1;
	if (ac > 1)
	{
		elem = ft_create_elem(av[i]);
		i++;
		while (i < ac)
		{
			tmp = elem;
			elem = ft_create_elem(av[i]);
			elem->next = tmp;
			i++;
		}
		return (elem);
	}
	else
		return (NULL);
}
