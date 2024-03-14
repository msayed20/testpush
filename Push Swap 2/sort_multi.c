/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:56:44 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 11:03:56 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_cheapest(stack_list **a, stack_list **b, cheapest_node *cheapest)
{
    while(cheapest->ra-- > 0)
        write_inst_rotate(a, b , "ra");
    while(cheapest->rb-- > 0)
        write_inst_rotate(a, b , "rb");
    while(cheapest->rra-- > 0)
        write_inst_reverse_rotate(a, b , "rra");
    while(cheapest->rrb-- > 0)
        write_inst_reverse_rotate(a, b , "rrb");
    while(cheapest->rr-- > 0)
        write_inst_rotate(a, b , "rr");
    while(cheapest->rrr-- > 0)
        write_inst_reverse_rotate(a, b , "rrr");
    while(cheapest->pb-- > 0)
        ft_pb(a, b);
}


void sort_multi(stack_list **a, stack_list **b)
{   
    target_node *target;
    moves_node *inst_a;
    moves_node *inst_b;
    cheapest_node *cheapest;

    target = malloc(sizeof(target_node));
    inst_a = malloc(sizeof(moves_node));
    inst_b = malloc(sizeof(moves_node));
    cheapest = malloc(sizeof(cheapest_node));
    ft_pb(a, b);
    ft_pb(a, b);
    while((lst_len(a)) != 3)
    {
        find_max_min_b(b, target);
        find_cheapest_move(a, b,target, inst_a, inst_b, cheapest);
        move_cheapest(a, b, cheapest);
    }
    sort_three(a, b);
    sort_stack_a(a, b, target, inst_a);
    free(target);
    free(inst_a);
    free(inst_b);
    free(cheapest);
}

