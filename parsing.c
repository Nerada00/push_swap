/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:17 by abdmessa          #+#    #+#             */
/*   Updated: 2024/01/24 06:00:11 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(char *str, t_data *data)
{
	int	i;

	i = 0;
	data->arg = ft_split(str, ' ');
	while (data->arg[i])
	{
		printf("%s\n", data->arg[i]);
		if (check_number(data->arg[i]) == 0)
		{
			free(data->arg[i]);
			return (printf("Error\n"),0);
		}
		i++;
	}
	free(data->arg);
	return (1);
}

