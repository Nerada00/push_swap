/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:31 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/23 05:11:28 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void free_list(t_list *head) 
{
    t_list *tmp;
    while (head) 
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print_stack(t_list *a)
{
    while (a)
    {
        printf("%d -> ", a->content);
        a = a->next;
    }
    printf("\n");
}

t_list    *init_stack(t_data *data, t_list *stack_a)
{
    t_list *node;
    int  i = 0;
    // printf("\n Liste principal avant tout mouvement\n");
    while (i < data->len)
    {
        node = ft_lstnew(data->tab[i], i);
        if (!node)
            return (NULL);
        ft_lstadd_back(&stack_a, node);
        i++;
        // printf(" =[%d]= ", node->content);
    }
    return (stack_a);
}

int main(int ac , char **av)
{
	t_data data;
    t_list *stack_a;
    t_list *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;

    if (ac > 2)
    {
        grab_arg(&data, ac, av);
        if (parse(&data, ac, av) == 0 )
            return (0);
        t_list *tmp = stack_b;
        t_list *tmp2;
        stack_a = init_stack(&data, tmp);
        if (check_sort(&stack_a) == 1)
            printf ("Liste deja triee\n");
        if (ac == 4)
            ft_sort_3(&stack_a);
        if (ac == 6)
            ft_sort_5(&stack_a, &stack_b);
        else if (check_sort(&stack_a) == 0)
            ft_sort(&stack_a, &stack_b);
        // printf ("\n---stack A---\n");
        print_stack(stack_a);
        free(data.tab);
        tmp2 = stack_a;
        free_list(stack_a);
    }
    else
        printf("Entrez minimum 2 arguments\n");
    return (0);
}
