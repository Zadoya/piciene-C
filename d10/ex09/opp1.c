/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:25:11 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/16 19:46:27 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usefull.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_div(int a, int b)
{
	if (b != 0)
	{
		ft_putnbr(a / b);
	}
	else
		ft_putstr("Stop : division by zero");
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}
