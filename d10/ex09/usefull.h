/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:53:13 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/16 19:54:15 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFULL_H
# define USEFULL_H

typedef struct	s_opp
{
	char *c;
	void (*f)(int, int);
}				t_opp;
int				ft_atoi(char *c);
void			ft_putstr(char *c);
void			ft_putnbr(int i);
void			ft_putchar(char c);
int				ft_strcmp(char *s1, char *s2);
void			ft_add(int a, int b);
void			ft_div(int a, int b);
void			ft_sub(int a, int b);
void			ft_mul(int a, int b);
void			ft_mod(int a, int b);
void			ft_usage(int a, int b);

#endif
