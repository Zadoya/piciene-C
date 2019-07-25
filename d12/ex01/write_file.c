/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:39:04 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/18 16:39:50 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	write_file(int ac, char **av)
{
	int	i;
	int	fd;

	i = 0;
	while (++i <= ac)
	{
		if (ft_strcmp(av[i], "-") == 0)
			write_term();
		else if ((fd = open(av[i], O_RDWR)) == -1)
		{
			ft_putstr(2, "cat: ");
			ft_putstr(2, av[i]);
			if (errno == 13)
				ft_putstr(2, ": Permission denied\n");
			else if (errno == 2)
				ft_putstr(2, ": No such file or directory\n");
			else if (errno == 21)
				ft_putstr(2, ": Is a directory\n");
		}
		else
			display(fd);
	}
}
