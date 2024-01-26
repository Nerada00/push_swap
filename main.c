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
    if (ac > 2)
    {
        arg_to_tab(av, &data, ac);
        display_tab(&data);
        if (check_doublons(&data) == 0)
        {
            printf("DOUBLONS\n");
            exit(0);
        }
    }
    else
        printf ("Manque d'argument");
}
