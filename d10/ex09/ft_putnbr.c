/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:55:24 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/16 19:52:27 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usefull.h"

void	ft_putnbr(int nb)
{
	long negative;

	negative = nb;
	if (negative < 0)
	{
		ft_putchar('-');
		negative *= -1;
	}
	if (negative > 9)
		ft_putnbr(negative / 10);
	ft_putchar(negative % 10 + '0');
}
