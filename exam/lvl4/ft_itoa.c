#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *ft_itoa(int nbr)
{
    char *str, *ptr;
    int del;
    long negativ;

    negativ = nbr;
    del = 1000000000;
    if (negativ == 0)
        return ("0\0");
    str = malloc(sizeof(char) * 11);
    ptr = str;
    if (nbr < 0)
    {
        *str++ = '-';
        negativ *= -1;
    }
    while (del > negativ)
        del /= 10; 
    while (del >= 1)
    {
        *str++ = negativ / del + '0';
        negativ %= del;
        del /= 10;
    }
    *str = '\0';
    return(ptr);
}

int main(int ac, char ** av)
{
    printf("%s", ft_itoa(5));
    return (0);
}