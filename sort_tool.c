/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:40:42 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/27 05:10:31 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mediane5(t_list **stack_a)
{
	int	mediane;

	mediane = 0;
	mediane = ft_lstsize(*stack_a) / 2 + 1;
	return (mediane);
}

void	ft_update_index(t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

int	check_sort(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_min(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = tmp->content;
	while (tmp)
	{
		if (i > tmp->content)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_max(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = tmp->content;
	while (tmp)
	{
		if (i < tmp->content)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}
