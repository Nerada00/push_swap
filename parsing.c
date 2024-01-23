/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:17 by abdmessa          #+#    #+#             */
/*   Updated: 2023/12/21 06:14:16 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char +*str)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][j] < 0 || str[i][j] > 9)
			return (0);
		j++;
	}
	return (1);
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	t_data data;
	data.arg = NULL;
	data.arg = ft_split(str, ' ');
	while (data.arg)
	{
		printf("%s", data.arg[i]);
		if (check_number(data.arg == 0)
		{
			return (printf("Error\n"),0);
			free(data.arg[i]);
		}
		else
			return (0);
	}
	free(data.arg);
	return (1);
}
