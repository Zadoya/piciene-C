#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}

int **pawn(int **desk, int i_p, int j_p, int size)
{
	if (i_p == size - 1)
		desk[i_p - 1][j_p - 1] = 1;
	else if (i_p == 0)
		desk[i_p - 1][j_p + 1] = 1;
	else
	{
		desk[i_p - 1][j_p - 1] = 1;
		desk[i_p - 1][j_p + 1] = 1;
	}
	return (desk);
}

int **bishop(int **desk, int i_p, int j_p, int size)
{
	int i;
	
	i = 0;
	while (i_p + i < size)
	{
		if (j_p - i >= 0)
			desk[i_p + i][j_p - i] = 1;
		if (j_p + i < size)
			desk[i_p + i][j_p + i] = 1;
		i++;
	}
	i = 0;
	while (i_p - i >= 0)
	{
		if (j_p - i >= 0)
			desk[i_p - i][j_p - i] = 1;
		if (j_p + i < size)
			desk[i_p - i][j_p + i] = 1;
		i++;
	}
	return (desk);
}

int **rook(int **desk, int i_p, int j_p, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		desk[i_p][i] = 1;
		desk[i][j_p] = 1;
		i++;
	}
	return (desk);
}

int check_mate(char **desk, int size)
{
	int **bin_desk;
	int *rows;
	int i;
	int j;
	int i_k;
	int j_k;

	if (size == 1)
		return (0);
	bin_desk = malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		rows = malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
			rows[j++] = 0;
		bin_desk[i++] = rows;
	}
	i = 1;
	while (i <= size)
	{
		j = 0;
		while (j < size)
		{
			if (desk[i][j] == 'P' && i != 1)
				bin_desk = pawn(bin_desk, i - 1, j, size);
			if (desk[i][j] == 'B')
				bin_desk = bishop(bin_desk, i - 1, j, size);
			if (desk[i][j] == 'R')
				bin_desk = rook(bin_desk, i - 1, j,size);
			if (desk[i][j] == 'Q')
			{
				bin_desk = rook(bin_desk, i - 1, j, size);
				bin_desk = bishop(bin_desk, i - 1, j, size);
			}
			if (desk[i][j] == 'K')
			{
				i_k = i - 1;
				j_k = j;
			}
			j++;
		}
		i++;
	}
	if (bin_desk[i_k][j_k] == 1)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1 && ac < 10)
	{
		if (check_mate(av, ac - 1))
			putstr("Success");
		else
			putstr("Fail");
	}
	putstr("\n");
	return (0);
}