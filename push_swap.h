/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:24 by abdmessa          #+#    #+#             */
/*   Updated: 2024/01/26 05:20:38 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_list
{
    char			*content;
	struct s_list	*next;
}           t_list;

typedef struct s_data
{
   char    **arg;
   int      *tab;
   int      len;
}           t_data;

// Lib

long int     ft_atoi(char const *str);
char	**ft_split(char const *s, char c);
int     ft_strlen(char *str);
int     ft_strlen2(char **str);

// Liste chainees

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);


//check

int     arg_to_tab(char **str, t_data *data, int ac);
void     display_tab(t_data *data);
int	    check_number(char *str);
int	    check_doublons(t_data *data);

#endif