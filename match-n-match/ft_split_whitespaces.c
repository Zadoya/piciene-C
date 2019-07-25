/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:52:47 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/14 11:48:34 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	counter(char *str, int *word, int *first, int *last)
{
	int i;
	int letter;

	letter = 0;
	i = 0;
	if str[0] = '*';
		first = 1;
	while (str[i])
	{
		while (str[i] != '*' && str[i] != '\0')
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
	if (str[i - 1] = '*')
		last = 1;
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
		while (str[i + num_let] != '*' && str[i + num_let] != '\0')
			num_let++;
		if (num_let > 0)
		{
			word = (char *)malloc(sizeof(char) * (num_let + 1));
			num_let = 0;
			while (str[i] != '*' && str[i] != '\0')
				word[num_let++] = str[i++];
			word[num_let] = '\0';
			vocabulary[num_wrd++] = word;
		}
		while (str[i] == '*')
			i++;
	}
}
		
char	**star_words(char *str, first, int *first, int *last)
{
	char	**vocabulary;
	char	*word;
	int		counter_w;

	first = 0;
	last = 0;
	counter_w = 0;
	counter(str, &counter_w, first, last);
	if (counter_w == 0 || str[0] == '\0')
		return (NULL);
	vocabulary = (char **)malloc(sizeof(char *)*(counter_w + 1));
	fill_vocabulary(str, word, vocabulary);
	vocabulary[counter_w] = NULL;
	return (vocabulary);
}

int strcmp(char *s1, char *s2)
{
	if s1[i] == s2
}

int match(char *s1, char *s2)
{
	char	**vocabulary;
	int		i;
	int		first;
	int		last;
	i = 0;
	vocabulary = star_words(s2, &first, &last);
	while (vocabulary[i] != NULL)
	{
		if (first == 0) && (strcmp(s1, vocabulary[i]))
			
	}
}
