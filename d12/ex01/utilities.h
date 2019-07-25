/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:23:05 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/18 22:23:11 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# define BUF_SIZE 25000

void	display(int fd);
void	write_file(int ac, char **av);
void	ft_putstr(int fd, char *str);
int		ft_strcmp(char *s1, char *s2);
void	write_term(void);

#endif
