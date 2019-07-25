#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

char **ft_split_whitespaces(char *str);

int     main(void)
{
    char arg[100] = "**g*r*g**rregerh*g****";
    char **a;
    int i = 0, j = 0;
    a = ft_split_whitespaces(arg);
    //if (a == NULL)
    //    printf("XYi");
   while (a[i] != NULL)
    {
        printf ("%s", a[i]);
        printf ("\n");
        i++;
    }
    return(0);
}
