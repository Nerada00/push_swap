#include "push_swap.h"

void    swap_a(t_list *stack_a)
{
    int tmp;
    if (!stack_a)
        return ;
    tmp = stack_a->content;
    stack_a->content = stack_a->next->content;
    stack_a->next->content = tmp;
    printf("sa\n");
}

void    swap_b(t_list *stack_b)
{
    int tmp;
    if (!stack_b)
        return ;
    tmp = stack_b->content;
    stack_b->content = stack_b->next->content;
    stack_b->next->content = tmp;
    printf("sb\n");
}

void    ss(t_list *stack_a, t_list *stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
}

void    push_b(t_list **stack_a, t_list **stack_b)
{
     if (!(*stack_a))
        return ;
    t_list  *tmp;
    tmp = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    tmp->next = (*stack_b);
    (*stack_b) = tmp;
    printf("pb\n");
}

void    push_a(t_list **stack_a, t_list **stack_b)
{
     if (!(*stack_b))
        return ;
    t_list  *tmp;
    tmp = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    tmp->next = (*stack_a);
    (*stack_a) = tmp;
    printf("pa\n");
}
void    rotate_a(t_list **stack_a)
{
    t_list  *tmp;
    t_list  *tmp2;

    tmp = (*stack_a);
    tmp2 = (*stack_a);
    while (tmp2->next != NULL)
    {
        tmp2 = tmp2->next;
    }
    (*stack_a) = (*stack_a)->next;
    tmp->next = NULL;
    tmp2->next = tmp;
    printf("ra\n");
}

void    rotate_b(t_list **stack_b)
{
    t_list  *tmp;
    t_list  *tmp2;

    tmp = (*stack_b);
    tmp2 = (*stack_b);
    while (tmp2->next != NULL)
    {
        tmp2 = tmp2->next;
    }
    (*stack_b) = (*stack_b)->next;
    tmp->next = NULL;
    tmp2->next = tmp;
    printf("rb\n");

}

void    rr(t_list *stack_a, t_list *stack_b)
{
    rotate_a(&stack_a);
    rotate_b(&stack_b);
}

// void    reverse_rotate_a(t_list *stack_a)
// {
    
// }