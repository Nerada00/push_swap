/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:31 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/16 07:05:49 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// evantuel probleme avec le 0
// check si les arguements sont corrects
    // rien a part des chiffres
    // au moins 2 nombres
// faire les mouvements
    // verifier que la pile nest pas vide avant de faire un mouvement
    // tous les TESTER dans plusieurs scenarios
//

#include "push_swap.h"

t_list    *init_stack(t_data *data, t_list *stack_a)
{
    t_list *node;
    size_t  i = 0;
    printf("\n Liste principal avant tout mouvement\n");
    while (data->tab[i])
    {
        node = ft_lstnew(data->tab[i]);
        ft_lstadd_back(&stack_a, node);
        i++;
        printf(" =[%d]= ", node->content);
    }
    printf("\n");
    return (stack_a);
}

int main(int ac , char **av)
{
	t_data data;
    t_list *stack_a;
    t_list *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;

    stack_b = ft_lstnew(111);

    
    if (ac > 2)
    {
        grab_arg(&data, ac, av);
        if (check_number(data.arg) == 0)
           return (printf("Arg contient des caractere non numerique\n"), 0);
        arg_to_tab(av, &data, ac);
        if (check_doublons(&data) == 0)
        {
            printf("DOUBLONS\n");
            exit(0);
        }
        // display_tab(&data);
        t_list *tmp = 0;
        t_list *tmp2;
        stack_a = init_stack(&data, tmp);
        // reverse_rotate_a(stack_a);
        tmp2 = stack_a;
        printf ("\n---stack A---\n");
        while (tmp2)
        {
            printf ("{%d} -> ", tmp2->content);
            tmp2 = tmp2->next;
        }
        printf ("\n---stack B---\n");
        while (stack_b)
        {
            printf ("{%d} -> ", stack_b->content);
            stack_b = stack_b->next;
        }
    }
    else
        printf("Entrez minimum 2 arguments\n");
}
