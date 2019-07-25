/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:48:02 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/16 20:50:52 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usefull.h"
#include "ft_opp.h"
#include <stdlib.h>

void	calculator(char **tab)
{
	int		i;
	int		(*a)(char *);
	void	(*f)(int, int);

	a = &ft_atoi;
	i = 0;
	f = NULL;
	while (i < 5)
	{
		if (ft_strcmp(g_opptab[i].c, tab[2]) == 0)
			f = g_opptab[i].f;
		i++;
	}
	if (!(f))
		f = g_opptab[5].f;
	if (f)
		f(a(tab[1]), a(tab[3]));
}

void	ft_usage(int a, int b)
{
	int n;

	n = a + b;
	n = 0;
	ft_putstr("error : only [ ");
	while (n < 5)
	{
		ft_putstr(g_opptab[n].c);
		ft_putstr(" ");
		n++;
	}
	ft_putstr("] are accepted.");
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		calculator(argv);
		ft_putstr("\n");
	}
	return (0);
}
