/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:24 by abdmessa          #+#    #+#             */
/*   Updated: 2024/02/28 00:36:32 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	char			**arg;
	long int		*tab;
	int				len;
	int				num_args;
	int				ra_rb;
	int				rra_rrb;
	int				rra_rb;
	int				ra_rrb;

}					t_data;

// ft_printf

int					ft_printf(const char *s, ...);
int					ft_putnbr(int nb);
int					ft_putchar(int c);
int					ft_putstr(char *str);
int					ft_count(int nb);
int					ft_print_digit(unsigned long int nb, char *base);
int					ft_print_format(char spec, va_list ap);
size_t				ft_strlen2(char *str);

// Lib

long int			ft_atoi(char const *str);
char				**ft_split(char const *s, char cft_checkint);
int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);

// Liste chainees

t_list				*ft_lstnew(int content, int pos);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_update_index(t_list **lst);

// check

void				grab_arg(t_data *data, int ac, char **av);
int					arg_to_tab(char **str, t_data *data, int ac);
void				display_tab(t_data *data);
int					check_number(char **str);
int					check_doublons(t_data *data);
int					parse(t_data *data, int ac, char **av);
int					check_sort(t_list **stack_a);
void				ft_putstr_fd(char *s, int fd);

// mouvement

void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				reverse_rotate_a(t_list **stack_a);
void				reverse_rotate_b(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				rr(t_list *stack_a, t_list *stack_b);
void				ss(t_list **stack_a, t_list **stack_b);

// tool
int					ft_max(t_list *lst);
int					ft_min(t_list *lst);
int					target_b(t_list *stack_b, int nbr_a);
int					find_pos(t_list *a, int nb);
int					ft_cost(t_list *a, t_list *b, int nbr_a, int nnr_b);
void				ft_min_cost(t_list *stack_a, t_list *stack_b, int *nbr_a,
						int *nbr_b);
int					ft_mediane5(t_list **stack_a);
int					target_b(t_list *stack_b, int nbr_a);

// algo
void				ft_sort(t_list **stack_a, t_list **stack_b);
void				second_part(t_list **stack_a, t_list **stack_b);
void				ft_sort_3(t_list **stack_a);
void				ft_sort_5(t_list **stack_a, t_list **stack_b);

// cost

int					sheap_cost(t_data cost);
int					compare(int a, int b);

#endif