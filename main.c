/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:31 by abdmessa          #+#    #+#             */
/*   Updated: 2024/01/26 05:20:42 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// evantuel probleme avec le 0
// check si les arguements sont corrects
    // rien a part des chiffres
    // au moins 2 nombres
// faire les mouvements
    // verifier que la pile nest pas vide avant de faire un mouvement
    // tous les TESTER dans plusieurs scenarios
//

#include "push_swap.h"

int main(int ac , char **av)
{
	t_data data;
    // int i = 1;
    if (ac > 2)
    {
        grab_arg(&data, ac, av);
        // data.num_args = 0;
        // data.arg = malloc(sizeof(char*) * ac-1);
        // while (i < ac)
        // {
        //     data.arg[i-1] = malloc(ft_strlen(av[i]) + 1);
        //     ft_strcpy(data.arg[i-1], av[i]);
        //     data.num_args++;
        //     i++;
        // }
        if (check_number(data.arg) == 0)
           return (printf("Arg contient des caractere non numerique"), 0);
        arg_to_tab(av, &data, ac);
        display_tab(&data);
        if (check_doublons(&data) == 0)
        {
            printf("DOUBLONS\n");
            exit(0);
        }
    }
    else
        printf ("Entrez minimum 2 arguments\n");
}
