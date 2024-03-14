/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:48:07 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/11 10:48:07 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    last_move(stack_list **a, stack_list **b, moves_node *inst_a)
{
    while(inst_a->ra-- > 0)
        write_inst_rotate(a, b, "ra");
    while(inst_a->rra-- > 0)
        write_inst_reverse_rotate(a, b, "rra");
}

void    last_sort(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a)
{
    int size;
    int first_num;
    int last_num;

    inst_a->ra = 0;
    inst_a->rra = 0;
    first_num = list_position(a, target->min_stack_a);
    last_num = list_position(a, target->max_stack_a);
    size = lst_len(a);
    if(first_num == 0 && last_num == size)
        return ;
    else
    {
        if(first_num + 1 > size / 2)
            inst_a->rra = (size - first_num);
        else
            inst_a->ra = first_num + 1;
            
        while(inst_a->ra-- > 0)
        {
            write_inst_rotate(a, b, "ra");
        }
        while(inst_a->rra-- > 0)
            write_inst_reverse_rotate(a, b, "rra");
    }
}


void sort_stack_a(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a)
{
    while((*b) != NULL)
    {
        find_max_min_a(a, target);
        if((*b)->data > target->max_stack_a)
            move_max(a, b, target, inst_a);
        else if((*b)->data < target->min_stack_a)
            move_min(a, b, target, inst_a);
        else
            find_new_num_a(a, b, (*b)->data, inst_a);
    }
    find_max_min_a(a, target);
    last_sort(a, b, target, inst_a);
    // ft_sort (a, b);
}

