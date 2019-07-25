/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:23:31 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/16 20:21:05 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tmp;

	i = 0;
	if (!(tmp = (int *)malloc(sizeof(int) * length + 1)))
		return (NULL);
	while (i < length)
	{
		tmp[i] = f(tab[i]);
		i++;
	}
	return (tmp);
}
