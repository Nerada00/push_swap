/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:17 by abdmessa          #+#    #+#             */
/*   Updated: 2024/01/26 04:43:26 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char **str)
{
	int 	i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '+' && str[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_doublons(t_data *data)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < data->len)
	{
		i = j + 1;
		while (i < data->len)
		{
			if (data->tab[j] == data->tab[i])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
