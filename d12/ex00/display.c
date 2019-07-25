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

#include "mylib.h"

int		display(char **av)
{
	char	buf[BUF_SIZE + 1];
	int		r;
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("open() error\n");
		return (1);
	}
	while ((r = read(fd, buf, BUF_SIZE)))
	{
		if (r == -1)
		{
			ft_putstr("read() error\n");
			return (1);
		}
		buf[r] = '\0';
		ft_putstr(buf);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() error\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	return (display(argv));
}
