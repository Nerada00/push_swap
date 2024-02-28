/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:40:58 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/27 23:58:39 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_a);
	tmp2 = (*stack_a);
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	ft_update_index(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_b);
	tmp2 = (*stack_b);
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	ft_update_index(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	rotate_a(&stack_a);
	rotate_b(&stack_b);
	ft_printf("rr\n");
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_a);
	tmp2 = (*stack_a);
	while (tmp2->next->next != NULL)
	{
		tmp2 = tmp2->next;
	}
	tmp = tmp2->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	tmp2->next = NULL;
	ft_update_index(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_b);
	tmp2 = (*stack_b);
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp = tmp2->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	tmp2->next = NULL;
	ft_update_index(stack_b);
	ft_printf("rrb\n");
}
