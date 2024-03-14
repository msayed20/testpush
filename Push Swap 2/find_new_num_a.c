/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_new_num_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:29:03 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 11:31:19 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num_a(stack_list **a, int num)
{
	stack_list	*temp;
    int smallest_largest;

    temp = *a;
    smallest_largest = INT_MAX; 
    while(temp != NULL)
    {
        if(smallest_largest > temp->data && temp->data > num)
            smallest_largest = temp->data;
        temp = temp->next;
    }
    return(smallest_largest);
}

void    find_new_num_a(stack_list **a, stack_list **b, int num, moves_node *inst_a)
{
    int position;
    int size;
    int nbr;

    inst_a->ra = 0;
    inst_a->rra = 0;
    size = lst_len(a);
    nbr = get_num_a(a, num);
    position = list_position(a, nbr);
    if(position == size)
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