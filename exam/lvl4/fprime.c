#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int num;

    num = 0;
    i = 0;
    while ((str[i] == '\n' || str[i] == '\t' || str[i] == ' ') && str [i])
        i++;
    if (str[i] == '-')
        return(num);
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + str[i] - '0';
        i++;
    }
    return(num);
}

void ft_putnbr(int num)
{
    char digit;

    if (num > 9)
        ft_putnbr(num / 10);
    digit = num % 10 + '0';
    write(1, &digit, 1);
}

int prime(int number)
{
    int i;

    i = 2;
    while (i < number)
    {
        if (!(number % i))
            return (0);
        i++;
    }
    return (1);
}

void fprime(int number)
{
    int i;
    int counter;

    counter = 0;
    i = 2;
    if (number == 1)
        ft_putnbr(number);
    while (i <= number)
    {
        if ((number % i == 0) && prime(i))
        {  
            //write(1, "XYI", 3);
            if (counter > 0)
                write(1, "*", 1);
            ft_putnbr(i);
            number = number / i;
            i = 2;
            counter++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        fprime(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (0);
}