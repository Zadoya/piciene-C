#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define BUF 4096

char cmp(char str1, char str2)
{
    return ((str1 == ')' && str2 == '(') || (str1 == '}' && str2 == '{') || (str1 == ']' && str2 == '['));
}

char brakets(char *str)
{
    int stack[BUF];    
    int i, top;

    i = 0;
    top = 0;
    while(str[i])
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            stack[++top] = str[i];
        else if ((str[i] == ')' || str[i] == ']' || str[i] == '}') && (cmp(str[i], stack[top])))
            stack[top--] = 0;
        i++;
    }
    if (top == 0)
        return (1);
    return (0);
}

int		main(int ac, char **av)
{
    unsigned int i;

    i = 1;
    if (ac > 1)
    {
        while (i < ac)
            if (brakets(av[i++]))
                write(1, "Ok", 2);
            else
                write(1,"Error", 5);
    }
	write(1, "\n", 1);
    return (0);
}