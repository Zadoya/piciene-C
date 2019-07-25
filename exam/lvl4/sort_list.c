#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *i;
    t_list *j;
    t_list *first;
    int tmp;

    i = lst;
    while(i)
    {
        j = i->next;
        while(j)
        {
            if (!((*cmp)((i->data), (j->data))))
            {
                tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return (lst);
}

int cmp(int a, int b)
{
    return (a <= b);
}

int main(int ac, char ** av)
{
    int tab[10] = {345, 45, 4554365, 325, 2147483647, 2, 45, 45, 1445, 4546};
    t_list *list, *prev;

    list = NULL;
    for (int i = 0; i < 10; i++)
    {
        prev = list;
        list = (t_list *)malloc(sizeof(t_list));
        list->data = tab[i];
        list->next = prev;
    }
    list = sort_list(list, cmp);
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    return (0);
}