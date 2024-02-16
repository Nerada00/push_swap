/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:24 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/16 06:57:20 by abdmessa         ###   ########.fr       */
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
    int			content;
	struct s_list	*next;
}           t_list;

typedef struct s_data
{
   char    **arg;
   int      *tab;
   int      len;
   int      num_args;

}           t_data;

// Lib

long int     ft_atoi(char const *str);
char	**ft_split(char const *s, char c);
int     ft_strlen(char *str);
int     ft_strlen2(char **str);
char	*ft_strcpy(char *dest, char *src);

// Liste chainees

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);


//check

void    grab_arg(t_data *data, int ac, char **av);
int     arg_to_tab(char **str, t_data *data, int ac);
void     display_tab(t_data *data);
int	    check_number(char **str);
int	    check_doublons(t_data *data);


//mouvement

void    swap_a(t_list *stack_a);
void    swap_b(t_list *stack_b);
void    push_b(t_list **stack_a, t_list **stack_b);
void    push_a(t_list **stack_a, t_list **stack_b);
void    rotate_a(t_list **stack_a);
void    rotate_b(t_list **stack_b);
void    reverse_rotate_a(t_list *stack_a);

#endif