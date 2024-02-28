/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:31 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/27 06:17:30 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	print_stack(t_list *a)
{
	while (a)
	{
		printf("%d -> ", a->content);
		a = a->next;
	}
}

t_list	*init_stack(t_data *data, t_list *stack_a)
{
	t_list	*node;
	int		i;

	i = 0;
	while (i < data->len)
	{
		node = ft_lstnew(data->tab[i], i);
		if (!node)
			return (NULL);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

void	already_sorted(t_list *stack_a, t_data *data)
{
	if (check_sort(&stack_a) == 1)
	{
		ft_putstr_fd("Error\nListe deja triee\n", 2);
		free(data->tab);
		free_list(stack_a);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data			data;
	static t_list	*stack_a = NULL;
	static t_list	*stack_b = NULL;
	t_list			*tmp;

	if (ac > 2)
	{
		grab_arg(&data, ac, av);
		if (parse(&data, ac, ++av) == 0)
			return (0);
		tmp = stack_b;
		stack_a = init_stack(&data, tmp);
		already_sorted(stack_a, &data);
		if (ac == 4)
			ft_sort_3(&stack_a);
		if (ac == 6)
			ft_sort_5(&stack_a, &stack_b);
		else if (check_sort(&stack_a) == 0)
			ft_sort(&stack_a, &stack_b);
		free(data.tab);
		free_list(stack_a);
	}
	else
		ft_putstr_fd("Error\nEntrez minimum 2 arguments\n", 2);
	return (0);
}
