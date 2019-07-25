#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
void sort_list(t_list **lst,int ref_data, int (*cmp)())
{
    t_list *i;
    t_list *prev;
    t_list *tmp;

    i = *lst;
    while(i)
    {
        tmp = i->next;
        if ((*cmp)(i->data, ref_data) == 0)
        {
            if (i == *lst)
            {
                *lst = i->next;
                free(i);
            }
            else
            {
                prev->next = i->next;
                free(i);
            }
        }
        else 
            prev = i;
        i = tmp;
    }
}

int cmp(int a, int b)
{
    return (a - b);
}

int main(int ac, char ** av)
{
    int tab[10] = {45, 45, 45, 325, 2147483647, 2, 45, 45, 4578, 4};
    t_list *list, *prev;

    list = NULL;
    for (int i = 0; i < 10; i++)
    {
        prev = list;
        list = (t_list *)malloc(sizeof(t_list));
        list->data = tab[i];
        list->next = prev;
    }
    sort_list(&list, 45, cmp);
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    return (0);
}