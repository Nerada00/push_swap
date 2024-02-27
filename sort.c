/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:40:31 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/27 05:02:31 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (a < b && b < c && a > c)
		rotate_a(stack_a);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	ft_mediane5(stack_a);
	find_pos(*stack_a, ft_min(*stack_a));
	while ((*stack_a)->content != ft_min(*stack_a))
	{
		if (find_pos(*stack_a, ft_min(*stack_a)) >= ft_mediane5(stack_a))
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	ft_min(*stack_a);
	find_pos(*stack_a, ft_min(*stack_a));
	while ((*stack_a)->content != ft_min(*stack_a))
	{
		if (find_pos(*stack_a, ft_min(*stack_a)) >= ft_mediane5(stack_a))
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	ft_sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp2;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (*stack_a)
	{
		if ((*stack_a)->content < ft_min(*stack_b)
			|| (*stack_a)->content > ft_max(*stack_b))
		{
			while ((*stack_b)->content != ft_max((*stack_b)))
				rotate_b(&(*stack_b));
			push_b(stack_a, stack_b);
		}
		else
			second_part(stack_a, stack_b);
	}
	while (*stack_b)
	{
		while ((*stack_b)->content != ft_max(*stack_b))
			rotate_b(stack_b);
		push_a(stack_a, stack_b);
		tmp2 = *stack_b;
		while (tmp2)
			tmp2 = tmp2->next;
	}
}

void	second_part(t_list **stack_a, t_list **stack_b)
{
	int	nbr_a;
	int	nbr_b;

	ft_min_cost((*stack_a), (*stack_b), &nbr_a, &nbr_b);
	while ((*stack_a)->content != nbr_a)
	{
		if (find_pos(*stack_a, nbr_a) > ft_mediane5(stack_a))
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	while ((*stack_b)->content != nbr_b)
	{
		if (find_pos(*stack_b, nbr_b) > ft_mediane5(stack_b))
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

int	target_b(t_list *stack_b, int nbr_a)
{
	t_list	*tmp;
	int		diff;
	int		n;

	tmp = stack_b;
	diff = 2147483647;
	n = ft_max(stack_b);
	while (tmp)
	{
		if (nbr_a - tmp->content < diff && nbr_a > tmp->content)
		{
			diff = nbr_a - tmp->content;
			n = tmp->content;
		}
		tmp = tmp->next;
	}
	return (n);
}
