#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

int w_counter(char *str)
{
    int i = 0;
    int counter = 0;

    while (str[i])
    {
        if ((str[i - 1] == '\n' || str[i - 1] == '\t' || str[i - 1] == ' ') &&
            (str[i] != '\n' && str[i] != '\t' && str[i] != ' '))
            counter++;
        i++;
    }
    return(counter);
}

char **fill_tab(char *str, char **tab)
{
    int i = 0;
    int counter = 0, w_counter = 0;
    char *word;
    while (str[i])
    {
        while(str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            i++;
        while(str[i +counter] != '\n' && str[i + counter] != '\t' && str[i + counter] != ' ' && str[i])
            counter++;
        if (!(word = malloc(counter)))
            return (NULL);
        counter = 0;
        while(str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
            word[counter++] = str[i++];
        word[counter] = '\0';
        tab[w_counter++] = word;
        counter = 0;
    }
    return (tab);
}

char **ft_split(char *str)
{
    int i;
    int word;
    char **tab;
    i = 0;
    word = w_counter(str);
    if (!(tab = (char **)malloc(sizeof(char *) * word + 1)))
        return(NULL);
    tab = fill_tab(str, tab);
    tab[word] = NULL;
    return (tab);
}

int main(int ac, char ** av)
{
    int i;
    int all;
    char **tab;
    if (ac == 2)
    {
        tab = ft_split(av[1]);
        while (tab[i])
            i++;
        all = i;
        while (i > 0)
        {
            if (i > 1 && all != i)
                ft_putstr(" ");
            ft_putstr(tab[--i]);
        }
    }
    ft_putstr("\n");
    return (0);
}