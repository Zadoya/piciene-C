#include <stdlib.h>
#include <unistd.h>

void putstr(char *str)
{
    int i = 0;

    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int w_counter(char *str)
{
    int i;
    int counter;

    counter = 0;
    i = 0;
    while(str[i])
    {
        while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            i++;
        while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
            i++;
        counter++;
    }
    return (counter);
}

char **split(char *str)
{
    char **tab;
    char *word;
    int i;
    int w;
    int counter;
    int count;

    i = 0;
    count = 0;
    w = w_counter(str);
    tab = malloc(sizeof(char *) * (w + 1));
    while (str[i])
    {
        while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            i++;
        counter = 0;
        while (str[i + counter] != '\n' && str[i + counter] != '\t'
                && str[i + counter] != ' ' && str[i + counter])
            counter++;
        if (counter > 0)
        {
            word = malloc(counter);
            counter = 0;
            while(str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i])
                word[counter++] = str[i++];
            word[counter] = '\0';
            tab[count++] = word;
        }
    } 
    tab[count] = NULL;
    return (tab);
}

void rostring(char *str)
{
    char **tab;
    int i;
    
    i = 1;
    tab = split(str);
    while (tab[i])
    {
        putstr(tab[i++]);
        putstr(" ");
    }
    putstr(tab[0]);
}

int main(int ac, char ** av)
{
    if(ac == 2)
    {
        rostring(av[1]);
    //    putstr(rostring(av[1]));
    }
    putstr("\n");
    return (0);
}