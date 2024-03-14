/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:47:57 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/11 10:47:57 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_max(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a)
{
    int position;
    int size;

    inst_a->ra = 0;
    inst_a->rra = 0;
    position = list_position(a, target->max_stack_a);
    
    size = lst_len(a);
    if(position - 1 == size)
        ft_pa(a, b);
    else
    {
        if(position + 1 > size / 2)
            inst_a->rra = (size - position);
        else
            inst_a->ra = position + 1;
    
        while(inst_a->ra-- > 0)
            write_inst_rotate(a, b, "ra");
        while(inst_a->rra-- > 0)
            write_inst_reverse_rotate(a, b, "rra");
        ft_pa(a, b);
    }
}

void    move_min(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a)
{
    int position;
    int size;

    inst_a->ra = 0;
    inst_a->rra = 0;
    position = list_position(a, target->min_stack_a);
    size = lst_len(a);
    if(position - 1 == size)
        ft_pa(a, b);
    else
    {
        if(position + 1 > size / 2)
            inst_a->rra = (size - position);
        else
            inst_a->ra = position;
        while(inst_a->ra-- > 0)
            write_inst_rotate(a, b, "ra");
        while(inst_a->rra-- > 0)
            write_inst_reverse_rotate(a, b, "rra");
        ft_pa(a, b);
    }
}
