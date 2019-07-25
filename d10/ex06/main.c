/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:48:02 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/16 18:13:27 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	calculator(char **tab, int (*f)(char *), void (*str)(char *))
{
	void (*nbr)(int);

	nbr = &ft_putnbr;
	if (tab[2][0] == '+')
		nbr(f(tab[1]) + f(tab[3]));
	else if (tab[2][0] == '-')
		nbr(f(tab[1]) - f(tab[3]));
	else if (tab[2][0] == '/')
		if (f(tab[3]) != 0)
		{
			nbr(f(tab[1]) / f(tab[3]));
		}
		else
			str("Stop : division by zero");
	else if (tab[2][0] == '%')
		if (f(tab[3]) != 0)
		{
			nbr(f(tab[1]) % f(tab[3]));
		}
		else
			str("Stop : modulo by zero");
	else if (tab[2][0] == '*')
		nbr(f(tab[1]) * f(tab[3]));
	else
		nbr(0);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		calculator(argv, ft_atoi, ft_putstr);
		ft_putstr("\n");
	}
	return (0);
}
