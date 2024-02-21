#include "push_swap.h"

void    push_b(t_list **stack_a, t_list **stack_b)
{
     if (!(*stack_a))
        return ;
    t_list  *tmp;
    tmp = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    tmp->next = (*stack_b);
    (*stack_b) = tmp;
    ft_update_index(*stack_a);
    ft_update_index(*stack_b);
    printf("pb\n");
    print_stack(*stack_a);
    print_stack(*stack_b);
}

void    push_a(t_list **stack_a, t_list **stack_b)
{
     if (!(*stack_b) || !(stack_b))
        return ;
    t_list  *tmp;
    tmp = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    tmp->next = (*stack_a);
    (*stack_a) = tmp;
    printf("%d\n", (*stack_a)->content);
    ft_update_index(*stack_a);
    ft_update_index(*stack_b);
    printf("pa\n");
    print_stack(*stack_a);
    print_stack(*stack_b);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
    printf("rrr\n");
}
