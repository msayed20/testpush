/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:25:06 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/13 13:16:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_list  *sort_three(stack_list **a, stack_list **b)
{
    if(!*a)
        return (NULL);
    stack_list *sorting;
    
    sorting = *a;
    if(sorting->data > sorting->next->data)
    {
        if(sorting->data > sorting->next->next->data)
            write_inst_rotate(a, b, "ra");
    }
    else if(sorting->next->data > sorting->data)
    {
        if(sorting->next->data > sorting->next->next->data)
            write_inst_reverse_rotate(a, b, "rra");
    }
    if((*a)->data > (*a)->next->data)
        write_inst_swap(a, b, "sa");
    return (*a);
}
