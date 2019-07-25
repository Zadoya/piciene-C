#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_itoa(char *str, int i, unsigned int value, int base)
{
    if (value >= base)
        i = ft_itoa(str, i, value / base, base);
    if (value % base < 10)
        str[i++] = value % base + '0';
    else
        str[i++] = value % base + '7';
    return(i);
}

char *ft_itoa_base(int value, int base)
{
    char znak = 0, *output, *ptr;
    unsigned int number;
    int i;

    i = 0;
    output = malloc(32);
    ptr = output;
    number = value;
    if (value < 0)
    {
        number *= -1;
        if (base == 10)
            output[i++] = '-';
    }
    i = ft_itoa(output, i, number, base);
    output[i] = '\0'; 
    return (ptr);
}

int		main(int ac, char **av)
{
	
	printf("%s\n", ft_itoa_base(213245, 16));
	return (0);
}