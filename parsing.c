/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:17 by abdmessa          #+#    #+#             */
/*   Updated: 2024/01/25 04:14:01 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	arg_to_tab(char *str, t_data *data)
{
	int	i;
	int	j = 0;

	i = 0;
	data->arg = ft_split(str, ' ');
	data->tab = malloc(sizeof(int) * ft_strlen2(data->arg));
	while (data->arg[i])
	{
		if (check_number(data->arg[i]) == 0)
		{
			free(data->arg[i]);
			return (printf("Error\n"),0);
		}
		data->tab[i] = ft_atoi(data->arg[i]);
		//printf("%d\n", data->tab[j]);
		j++;
		i++;
	}
	free(data->arg);
	return (1);
}

