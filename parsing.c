/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:17 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/17 04:48:55 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char **str)
{
	int 	i;
	int 	j;

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
	int i;

	i = 0;
	while(data->len > i)
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
	{
        	// free(data->tab);
           return (printf("Arg contient des caractere non numerique\n"), 0);
	}
    arg_to_tab(av, data, ac);
    if (check_doublons(data) == 0)
    {
        free(data->tab);
        printf("DOUBLONS\n");
        return(0);
    }
	 if (ft_checkint(data) == 0 )
    {
        free(data->tab);
		printf("Erreur le programme ne prend pas de long ");
		return(0);
    }
	return (1);
}
