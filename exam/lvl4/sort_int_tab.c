#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int num)
{
    long negative;

    negative = num;
    if (negative < 0)
    {
        ft_putchar('-');
        negative *= -1;
    }
    if (negative > 9)
        ft_putnbr(negative / 10);
    ft_putchar(negative % 10 + '0');
}

void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while(i < size)
    {
        j =0;
        while(j < size)
        {
            if (tab[i] < tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(i < size)
    {
        ft_putnbr(tab[i++]);
        if (i != size)
            ft_putchar(' ');
    }
}

int main(int ac, char ** av)
{
    int tab[10] = {345, 45, 4554365, 325, 2147483647, 2, 45, 45, 1445, 4546};
    sort_int_tab(tab, 10);
    return (0);
}