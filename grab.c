#include "push_swap.h"

void display_tab(t_data *data)
{
    int i = 0;
    while (i < data->len)
    {    
        printf("[%d]\n", data->tab[i]);
        i++;
    }
}

int    arg_to_tab(char **str, t_data *data, int ac)
{
    int i = 1;
    int j = 0;
    data->len = 0;
    data->tab = malloc(sizeof(int)* ac);
    while (str[i])
    {
        data->tab[j] = ft_atoi(str[i]);
        data->len++;
        i++;
        j++;
    }
    return (1);
}