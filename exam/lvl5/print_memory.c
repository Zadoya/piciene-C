#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void hex(int num, char *number, int *i)
{
    char *simbols = "0123456789abcdef";

    if (num >= 16)
        hex(num / 16, number, i);
    number[(*i)++] = simbols[num % 16]; 
}

void print_memory(int *addr, size_t size) //int change to const void*
{
    int i = 0, j, *bit;
    char number[64];
    char printable;
    while (i < size)
    {
        j = 16 / sizeof(addr);
        *bit = 0; 
        while (j > 0)
        {
            hex(addr[++i], number, bit);
            j--;
        }
        i -= 16 / sizeof(addr);
        while (j < 64)
        {
            if (j % 4  == 0 && j != 0)
                write(1, " ", 1);
            write(1, &number[j++], 1);
        }
        //???
        {
            if 
}

int		main(void)
{
    int tab [10] = {0, 23, 150, 255, 12, 16, 21, 42};
    print_memory(tab, 10);
    return (0);
}