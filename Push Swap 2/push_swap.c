/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:20:45 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:49:42 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    stack_list *a;
    stack_list *b;
    char *str;
    char **split;
    
    a = NULL;
    b = NULL;
    if(ac > 1)
    {
        check_arg(ac, av);
        str = join_arg(ac,av);
        split = split_arg(str);
        free_str(str);
        create_stack(&a, split);
        if(a == NULL)
            ft_free_list(&a);
        else
        {
            ft_sort(&a, &b);
            ft_printList(a);
            // ft_printList(b);
            last_free_list(&a);
            last_free_list(&b);
        }
    }
    else
        return (0);
}
