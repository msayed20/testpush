/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pa_pb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:13:28 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/12 11:43:50 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pa(stack_list **a, stack_list **b)
{
    stack_list *temp;

    if(!*b)
        return ;
    temp = *b;
    if((*b)->next != NULL)
        *b = (*b)->next;
    else
        *b = NULL;

    temp->next = *a;
    *a = temp;
    write(1, "pa\n", 3);
}

void    ft_pb(stack_list **a, stack_list **b)
{
    stack_list *temp;

    if(!*a)
        return ;
    temp = *a;
    *a = (*a)->next;

    temp->next = *b;
    *b = temp;
    write(1, "pb\n", 3);
}