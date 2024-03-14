/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:43:35 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:15:27 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    calculate_cheap(moves_node *inst_a, moves_node *inst_b, cheapest_node *cheapest, int c)
{
    inst_a->total = inst_a->ra + inst_a->rra + inst_a->rrr
        + inst_b->rb + inst_a->rr + inst_b->rrb + inst_a->pb + inst_b->sb;
    if(c == 1 || inst_a->total < cheapest->total)
    {
        cheapest->total = inst_a->total;
        cheapest->ra = inst_a->ra;
        cheapest->rra = inst_a->rra;
        cheapest->rrr = inst_a->rrr;
        cheapest->rr = inst_a->rr;
        cheapest->rb = inst_b->rb;
        cheapest->rrb = inst_b->rrb;
        cheapest->pb = inst_a->pb;
        cheapest->sb = inst_b->sb;
    }   
}

void    check_doubles(moves_node *inst_a, moves_node *inst_b)
{
    inst_a->rrr = 0;
    inst_a->rr = 0;
    while(inst_a->ra != 0 && inst_b->rb != 0)
    {
        inst_a->ra--;
        inst_b->rb--;
        inst_a->rr++;
    }
    while(inst_a->rra != 0 && inst_b->rrb != 0)
    {
        inst_a->rra--;
        inst_b->rrb--;
        inst_a->rrr++;
    }
}

void find_cheapest_move(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a, 
    moves_node *inst_b, cheapest_node *cheapest)
{
    stack_list *temp;
    int current_num;
    int size;
    int c;

    temp = *a;
    current_num = 0;
    c = 0;
    size = lst_len(a);
    while(c++ < size)
    {
        current_num = temp->data;
        get_a(a, inst_a, current_num, c - 1);
        if(current_num > target->max_stack_b 
            || current_num < target->min_stack_b)
            check_move_max_b(b, inst_b, target);
        else
            find_new_num(b, current_num, target, inst_b);
        check_doubles(inst_a, inst_b);
        calculate_cheap(inst_a, inst_b, cheapest, c);
        temp = temp->next;
    }
}

