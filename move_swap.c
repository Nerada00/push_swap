/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:27:21 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/23 04:39:40 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *stack_a)
{
	int	tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	ft_update_index(stack_a);
	printf("sa\n");
}

void	swap_b(t_list *stack_b)
{
	int	tmp;

	if (!stack_b)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	ft_update_index(stack_b);
	printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	printf("ss\n");
}
