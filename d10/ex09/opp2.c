/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:34:42 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/16 20:51:05 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usefull.h"

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_mod(int a, int b)
{
	if (b != 0)
	{
		ft_putnbr(a % b);
	}
	else
		ft_putstr("Stop : modulo by zero");
}
