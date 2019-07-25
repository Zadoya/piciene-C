#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void putnbr(int *number)
{
    unsigned int i;
    if (number < 0)
        write(1, "-", 1);
    if 
    
}

int calc(char * str)
{

}

int		main(int ac, char **av)
{
    int rez;

    if (ac == 2)
        if ((rez = calc(av[1])))
            putnbr()
    else
        write(1, "Error", 5); 
    return (0);
}