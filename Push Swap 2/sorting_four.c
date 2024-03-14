/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 08:43:14 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/13 21:25:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_list *sort_four(stack_list **a, stack_list **b)
{
    stack_list *temp;
    int num1;

    num1 = (*a)->data;
    ft_pb(a, b);
    sort_three(a, b);
    if(num1 > (*a)->next->data && num1 < (*a)->next->next->data)
    {
        write_inst_reverse_rotate(a, b, "rra");
        ft_pa(a, b);
        write_inst_rotate(a, b, "ra");
        write_inst_rotate(a, b, "ra");
    }
    else
        ft_pa(a, b);
    temp = *a;
    if(temp->data > temp->next->data)
    {
        temp = temp->next;
        if((*a)->data > temp->next->data && (*a)->data > temp->next->next->data)
            write_inst_rotate(a, b, "ra");
        else if((*a)->data < temp->next->data)
            write_inst_swap(a, b, "sa");
    }
    return (*a);
}

