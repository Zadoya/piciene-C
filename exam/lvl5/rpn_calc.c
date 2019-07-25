#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct list
{
    struct list *next;
    int value;
} t_list;

void putnbr(int number)
{
    unsigned int i;
    char s;
    i = number;
    if (number < 0)
    {
        write(1, "-", 1);
        i = i * -1;
    }
    if (i >= 10)
        putnbr(i / 10);
    s = i % 10 + '0';
    write(1, &s, 1);
}

int calc(t_list **num, t_list **oper)
{
    t_list *first = *num;
    t_list *second = (*num)->next;
    t_list *tmp;
    printf ("%d      %d\n",first->value, second->value);
    while (second)
    {
        if ((*oper)->value == '+')
            second->value = first->value + second->value;
        else if ((*oper)->value == '-')
            second->value = first->value - second->value; 
        else if ((*oper)->value == '/')
            second->value = first->value / second->value;
        else if ((*oper)->value == '*')
            second->value = first->value * second->value; 
        else
            second->value = first->value % second->value;
        tmp = (*oper);
        *oper = (*oper)->next;
        free(tmp);
        tmp = first;
        first = second; 
        second = second->next;
        free(tmp);
    }
    return (first->value);
}

int ft_atoi(char *str, int i)
{
    int znak = 1;
    int number = 0;

    if (str[i - 1] == '-')
        znak = -1;
    while (str[i] >= '0' && str[i] <= '9')
        number = number * 10 + str[i++] - '0';
    return (znak * number);
}

/*int reader(char *str, t_list **num, t_list **oper)
{
    int i = 0;
    t_list *tmp = NULL;
    int c_oper = 0;
    int c_num = 0;

    while(str[i])
    {
        if ((str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%') && (str[i + 1] == 0 || str[i + 1] == ' '))
        {
            if (*oper != NULL)
                tmp = *oper;
            *oper = malloc(sizeof(t_list));
            (*oper)->value = str[i];
            (*oper)->next = tmp;
            c_oper++;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {  
            if (*num != NULL)
                tmp = *num;
            *num = malloc(sizeof(t_list));
            (*num)->value = ft_atoi(str, i);
            printf ("%d\n",(*num)->value);
            (*num)->next = tmp;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
            c_num++;
        }
        i++;
    }
    printf ("%d      %d\n",c_oper, c_num);
    if (c_oper + 1 == c_num)
    {
        return(1);
    }
    else
        return(0);
}*/

int str_len(char *str)  // через обратное чтение и длинну строки, работает
{
    int i = 0;

    while(str[i])
        i++;
    return (i);
}

int reader(char *str, t_list **num, t_list **oper)
{
    int i = str_len(str);
    t_list *tmp = NULL;
    int c_oper = 0;
    int c_num = 0;

    while(i >= 0)
    {
        if ((str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%') && (str[i + 1] == 0 || str[i + 1] == ' '))
        {
            if (*oper != NULL)
                tmp = *oper;
            *oper = malloc(sizeof(t_list));
            (*oper)->value = str[i];
            (*oper)->next = tmp;
            c_oper++;
        }
        if (str[i] >= '0' && str[i] <= '9' && (i == 0 || str[i - 1] == ' ' || str[i - 1] == '-'))
        {  
            if (*num != NULL)
                tmp = *num;
            *num = malloc(sizeof(t_list));
            (*num)->value = ft_atoi(str, i);
            printf ("%d\n",(*num)->value);
            (*num)->next = tmp;
            c_num++;
        }
        i--;
    }
    printf ("%d      %d\n",c_oper, c_num);
    if (c_oper + 1 == c_num)
    {
        return(1);
    }
    else
        return(0);
}

int		main(int ac, char **av)
{
    int len;
    t_list *numbers = NULL;
    t_list *operands = NULL;
    if (ac == 2)
    {
        if (reader(av[1], &numbers, &operands))
            putnbr(calc(&numbers, &operands));
        else
            write(1, "Error", 5);
    }
    else
        write(1, "Error", 5); 
    return (0);
}