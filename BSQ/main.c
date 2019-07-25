#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int g_width;
int g_height;

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int    measure(char *str)
	{
    int i;

    g_width = 0;
    g_height = 0;
    i = 0;
    while (str[i] != '\n' && str[i])
        i++;
   	g_width = ++i;
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
	        g_height++;
        i++;
	}
	printf("%d", g_height);
    if (g_width < g_height)
        return (g_width);
    else
        return (g_height);
}

char **reader(char *str)
{
    char **tab;
    char *string;
    int i;
    int j;
    int jj;
    
    j = 0;
    i = 0;
    tab = (char **)malloc(sizeof(char *) * (g_height));
    while(str[i] && j < g_height)
    {
        string = (char *)malloc(sizeof(char) * (g_width));
        jj = 0;
        while (str[i] != '\n' && str[i])
          string[jj++] = str[i++];
        string[jj] = '\0';
        tab[j] = string;
        i++;
        j++;
    }
    return (tab);
}

int search(char **str, int max)
{
	int i;
	int j;
	int counter;
	int down;
	int left;

	i = 0;
	j = 0;
	counter = 0;
	down = 0;
	left = 0;
	while(max > 0)
	{ 
		if (str[i][j] != '.')
			counter++;
		if(i == max && j != max)
			j++;
		if (i == max && j == max && counter == 0)
			return(max);
		if ((j + down) != g_height && (i + left) != g_width)
		{
			left++;			//сдвигаю квадрат вниз
			i = 0;
			j = 0;
		}
		if (j == max && (j + down) != g_height && (i + left) == g_width)
		{
			down++;			//сдвигаю квадрат вниз
			i = 0;
			j = 0;
		}
		if (j == max && (j + down) == g_height && (i + left) == g_width)
			return (search(str, max - 1));
		i++;
	}
	return (123);
}

int main(int ac, char **av)
{
	int i;
	int max;

    i = 1;
	//printf("XYI");
    if(ac > 1)
        while (i <= ac)
		{
			max = measure(av[i]);
			printf("%d", max);
            //if (search(reader(av[i]), max - 1)
			//	printf("%d", search(reader(av[i]), max - 1));
			//else
				ft_putstr("Error!");
			i++;
		}
	return (0);		
}