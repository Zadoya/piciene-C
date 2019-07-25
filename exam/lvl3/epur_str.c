#include <unistd.h>

void del(char *str)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (str[i])
    {
        while (str[i] != '\n' && str[i] !='\t' && str[i] != ' ' && str[i])
        {
            if (counter && (str[i - 1] == '\n' || str[i - 1] =='\t' || str[i - 1] == ' '))
                write(1, " ", 1);
            write(1, &str[i++], 1);
            counter++;
        }
        i++;
    }
}

int main(int av, char **ac)
{
    if (av == 2)
        del(ac[1]);
    write(1, "\n", 1);
    return (0);
}