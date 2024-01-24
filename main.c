/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdmessa <abdmessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:00:31 by abdmessa          #+#    #+#             */
/*   Updated: 2024/01/24 06:23:32 by abdmessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// make
// int min -2147483648
// int max 2147483647
// check si les arguements sont corrects
    // rien a part des chiffres
    // check intmin intmax
    // pas de doublons
    // au moins 2 nombres
// faire les mouvements
    // verifier que la pile nest pas vide avant de faire un mouvement
    // tous les TESTER dans plusieurs scenarios
//

#include "push_swap.h"

int main(int ac , char **av)
{
    (void)ac;
	t_data data;
    for (int i = 1; i < ac; i++)
    {
        if (check_arg(av[i], &data) == 0)
            return (1);
    }
    return (0);
}
