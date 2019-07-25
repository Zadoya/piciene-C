/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:34:24 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/10 15:11:54 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		scmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	sort(char **ar, int l, int r)
{
	char	*tmp;
	int		i;
	int		j;
	int (*cmp)(char *, char *);

	cmp = &scmp;
	i = l;
	while (i < r)
	{
		j = l;
		while (j < r - 1)
		{
			if (cmp(ar[j], ar[j + 1]) > 0)
			{
				tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	sort(argv, i, argc);
	while (i <= argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
