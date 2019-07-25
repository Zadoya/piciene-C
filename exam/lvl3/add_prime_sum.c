#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int number;
    int znak;

    znak = 0;
    i = 0;
    while(str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
        i++;
    if (str[i] == '-')
    {
        znak = 1;
        i++;
    }
    if (str[i] == '+')
        i++;
    number = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        number = number * 10 + str[i] - '0';
        i++;
    }
    if (znak == 1)
        number *= -1;
    return (number); 
}

int prime(int num)
{
    int i;
    i = 2;

    while(i < num)
    {
        if(!(num % i))
            return(0);
        i++;
    }
    return (1);
}

int prime_sum(int number)
{
    int znak;
    int i;
    int sum;

    sum = 0;
    i = 2;
    znak = 0;
    if (number < 0)
    {
        znak = 1;
        number *= -1;
    }
    while (i <= number)
    {
        if (prime(i))
            sum += i;
        i++;
    }
    if (znak == 1)
        return (-sum);
    return (sum);
}

void putnbr(int number)
{
    char sign;
    int j;

    j = 1000000000;
    if (number < 0)
    {
        write(1, "-", 1);
        number *= -1;
    }
    while (number != 0)
    {
        if ((sign = number / j))
        {
            sign = sign + '0';
            write(1, &sign, 1);
        }
        number = number % j;
        j = j / 10;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        putnbr(prime_sum(ft_atoi(av[1])));
    return(0);
}