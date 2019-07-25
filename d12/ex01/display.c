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

void	display(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		r;

	while ((r = read(fd, buf, BUF_SIZE)))
	{
		buf[r] = '\0';
		ft_putstr(1, buf);
	}
	close(fd);
}
