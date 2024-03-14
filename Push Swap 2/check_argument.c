/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:28:04 by suhelal           #+#    #+#             */
/*   Updated: 2024/02/28 11:26:07 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_arg(int c, char **av)
{
    int count;

    count = 1;
    while(count < c)
    {
        if(!av[count][0])
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        count++;
    }
}
