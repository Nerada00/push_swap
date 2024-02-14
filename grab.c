#include "push_swap.h"

void    grab_arg(t_data *data, int ac, char **av)
{
    int i = 0;  
    data->num_args = 0;
    data->arg = malloc(sizeof(char*) * ac-1);
    while (i < ac)
    {
        data->arg[i-1] = malloc(ft_strlen(av[i]) + 1);
        ft_strcpy(data->arg[i-1], av[i]);
        data->num_args++;
        i++;
    }
}


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