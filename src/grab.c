/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:40:38 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/27 04:43:12 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	grab_arg(t_data *data, int ac, char **av)
{
	data->arg = ++av;
	(void)ac;
}

void	display_tab(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len)
		i++;
}

int	arg_to_tab(char **str, t_data *data, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->len = 0;
	data->tab = malloc(sizeof(long int) * ac);
	if (!data->tab)
		return (0);
	while (str[i])
	{
		data->tab[j] = ft_atoi(str[i]);
		data->len++;
		i++;
		j++;
	}
	return (1);
}
