/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:17 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/27 06:15:36 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	check_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = (str[i][0] == '+' || str[i][0] == '-');
		if (!str[i][j])
			return (0);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
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

int	ft_checkint(t_data *data)
{
	int	i;

	i = 0;
	while (data->len > i)
	{
		if (data->tab[i] > INT_MAX || data->tab[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	parse(t_data *data, int ac, char **av)
{
	if (check_number(data->arg) == 0)
		return (ft_putstr_fd("Error\nArg contient des caractere non numerique\n", 2), 0);
	arg_to_tab(av, data, ac);
	if (check_doublons(data) == 0)
	{
		free(data->tab);
		ft_putstr_fd("Error\nDOUBLONS\n", 2);
		return (0);
	}
	if (ft_checkint(data) == 0)
	{
		free(data->tab);
		ft_putstr_fd("Error\nLe programme ne prend pas de long\n", 2);
		return (0);
	}
	return (1);
}
