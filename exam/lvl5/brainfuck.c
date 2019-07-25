#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void brainfuck(char *str)
{
    int counter, rev_counter;
    int i,j;
    char *ptr;

    i = 0;
    j = 0;
    ptr = malloc(2048);
    counter = 0;
    while(str[i])
    {
        if (str[i] == '.')
            write(1, ptr, 1);
        if (str[i] == '+')
            (*ptr)++;
        if (str[i] == '-')
            (*ptr)--;
        if (str[i] == '>')
            ptr++;
        if (str[i] == '<')
            ptr--;
        if (str[i] == '[' && *ptr == 0)
        {
            counter++;
            while(counter)
            {
                i++;
                if (str[i] == ']')
                    counter--;
                if (str[i] == '[')
                    counter++;
            }
        }
        else if (str[i] == ']' && *ptr != 0)
        {
            counter++;
            while(counter)
            {
                i--;
                if(str[i] == ']')
                    counter++;
                if(str[i] == '[')
                    counter--;
            }
        }
        printf("%d ", i);
        i++;
    }
} 

int		main(int ac, char **av)
{
    if (ac == 2)
        brainfuck(av[1]);
	write(1, "\n", 1);
    return (0);
}