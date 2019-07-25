/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:15:12 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/09 23:03:39 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	unsigned int j;
	unsigned int len_d;
	unsigned int len_s;
	
	len_d = 0;
	len_s = 0;
	j = 0;
	while (dest[len_d] != '\0')
		len_d++;
	while (src[len_s] != '\0')
		len_s++;
	if (len_d  >= size)
		return (size + len_s);
	else 
	{
		i = size - len_d;
		while (src[j] != '\0' || i > 0)
		{
			dest[len_d + j] = src[j];
			j++;
			i--;
		}
	}
	dest[size] = '\0';
	return (len_d + len_s);
}
