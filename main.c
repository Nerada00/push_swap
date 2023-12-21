/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:31 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/21 06:00:32 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int ac , char **av)
{
    (void)ac;
    char    *a = av[1];
    char    *b = av[2];
    char    *c = av[3];
    t_list *list;
    t_list *list2;
    t_list *list3;

    list = ft_lstnew(a);
    list2 = ft_lstnew(b);
    list3 = ft_lstnew(c);
    ft_lstadd_back(&list, list2);
    ft_lstadd_back(&list, list3);
    printf("[%s] -> ", list->content);
    printf("[%s] -> ", list->next->content);
    printf("[%s]\n", list->next->next->content);

    printf("[%s] -> ", list->content);
    printf("[%s] -> ", list->next->content);
    printf("[%s]\n", list->next->next->content);
    return (0);
}
