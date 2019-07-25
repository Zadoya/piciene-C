/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:22:44 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/18 22:22:48 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	write_term(void)
{
	char *c;

	while (read(0, &c, 1))
		write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write_term();
	else
		write_file(argc - 1, argv);
	return (0);
}
