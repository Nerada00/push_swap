/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:40:35 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/27 05:32:21 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_cost(t_list *stack_a, t_list *stack_b, int *nbr_a, int *nbr_b)
{
	t_list	*tmp;
	int		n;
	int		cost;

	tmp = stack_a;
	cost = 2147483647;
	*nbr_a = tmp->content;
	*nbr_b = stack_b->content;
	while (tmp)
	{
		n = target_b(stack_b, tmp->content);
		if (ft_cost(stack_a, stack_b, tmp->content, n) < cost)
		{
			cost = ft_cost(stack_a, stack_b, tmp->content, n);
			*nbr_a = tmp->content;
			*nbr_b = n;
		}
		tmp = tmp->next;
	}
}

int	compare(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	sheap_cost(t_data cost)
{
	int	min;

	min = cost.ra_rb;
	if (min >= cost.ra_rrb)
		min = cost.ra_rrb;
	if (min >= cost.rra_rb)
		min = cost.rra_rb;
	if (min >= cost.rra_rrb)
		min = cost.rra_rrb;
	return (min);
}

int	ft_cost(t_list *a, t_list *b, int nbr_a, int nbr_b)
{
	int		pos_a;
	int		pos_b;
	t_data	cost;

	pos_a = find_pos(a, nbr_a);
	pos_b = find_pos(b, nbr_b);
	cost.ra_rb = compare(pos_a, pos_b);
	cost.ra_rrb = pos_a + (ft_lstsize(b) - pos_b);
	cost.rra_rb = (ft_lstsize(a) - pos_a) + pos_b;
	cost.rra_rrb = compare((ft_lstsize(a) - pos_a), (ft_lstsize(b) - pos_b));
	return (sheap_cost(cost));
}

int	find_pos(t_list *a, int nb)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->content == nb)
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (0);
}
