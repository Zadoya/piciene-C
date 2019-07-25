/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:52:47 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/12 14:59:32 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	counter(char *str, int *word)
{
	int i;
	int letter;

	letter = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'
				&& str[i] != '\0')
		{
			letter++;
			i++;
		}
		if (letter > 0)
		{
			*word = *word + 1;
			letter = 0;
		}
		i++;
	}
}

void	fill_vocabulary(char *str, char *word, char **vocabulary)
{
	int		i;
	int		num_let;
	int		num_wrd;

	i = 0;
	num_wrd = 0;
	while (str[i] != '\0')
	{
		num_let = 0;
		while (str[i + num_let] != ' ' && str[i + num_let] != '\n'
				&& str[i + num_let] != '\t' && str[i + num_let] != '\0')
			num_let++;
		if (num_let > 0)
		{
			word = (char *)malloc(sizeof(char) * (num_let + 1));
			num_let = 0;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'
					&& str[i] != '\0')
				word[num_let++] = str[i++];
			word[num_let] = '\0';
			vocabulary[num_wrd++] = word;
		}
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
	}
}

char	**ft_split_whitespaces(char *str)
{
	char	**vocabulary;
	char	*word;
	int		counter_w;
	int		i;

	counter_w = 0;
	counter(str, &counter_w);
	if (counter_w == 0 || str[0] == '\0')
		return (NULL);
	vocabulary = (char **)malloc(sizeof(char *) * (counter_w + 1));
	fill_vocabulary(str, word, vocabulary);
	i = 0;
	vocabulary[counter_w] = NULL;
	return (vocabulary);
}
