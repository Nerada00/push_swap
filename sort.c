#include "push_swap.h"

// si index du plus petit elem <
// int	ft_mediane(t_list **stack_a, int size)
// {
// 	int	mediane;

// 	if (size % 2 == 0 || size % 2 != 0)
// 		mediane = ft_lstsize(stack_a) / 2;
// 	return (mediane);
// }

void	ft_update_index(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
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
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a > b && b < c && a < c)
		swap_a(*stack_a);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		reverse_rotate_a(stack_a);
		swap_a(*stack_a);
	}
	else if (a < b && b < c && a > c)
		rotate_a(stack_a);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->content != ft_min(*stack_a))
		rotate_a(stack_a);
	if ((*stack_a)->content == ft_min(*stack_a))
		push_b(stack_a, stack_b);
	while ((*stack_a)->content != ft_min(*stack_a))
		rotate_a(stack_a);
	if ((*stack_a)->content == ft_min(*stack_a))
		push_b(stack_a, stack_b);
	ft_sort_3(stack_a);

	if ((*stack_b)->content > (*stack_b)->next->content)
	{
		// swap_b(*stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);

	}
	else
	{
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}

}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int		nbr_a;
	int		nbr_b;
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
		{
			ft_min_cost((*stack_a), (*stack_b), &nbr_a, &nbr_b);
			while ((*stack_a)->content != nbr_a)
				rotate_a(stack_a);
			while ((*stack_b)->content != nbr_b)
				rotate_b(stack_b);
			push_b(stack_a, stack_b);
		}
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

int	ft_cost(t_list *a, t_list *b, int nbr_a, int nbr_b)
{
	int	pos_a;
	int	pos_b;

	pos_a = find_pos(a, nbr_a);
	pos_b = find_pos(b, nbr_b);
	return (pos_a + pos_b);
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
