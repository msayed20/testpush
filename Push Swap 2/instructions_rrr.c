/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:17:49 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:15:41 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rra(stack_list **a)
{
    stack_list *temp;
    stack_list *new_stack;

    temp = *a;
    new_stack = NULL;

    while(temp->next != NULL)
    {
        new_stack = temp;
        temp = temp->next;
    }
    temp->next = *a;
    *a = temp;
    new_stack->next = NULL;
}

void    ft_rrb(stack_list **b)
{
    stack_list *temp;
    stack_list *new_stack;

    temp = *b;
    new_stack = NULL;

    while(temp->next != NULL)
    {
        new_stack = temp;
        temp = temp->next;
    }
    temp->next = *b;
    *b = temp;
    new_stack->next = NULL;
}

void ft_rrr(stack_list **a, stack_list **b)
{
    ft_rra(a);
    ft_rrb(b);
}

void write_inst_reverse_rotate(stack_list **a, stack_list **b, char *str)
{
    if((ft_strcmp(str, "rra")) == 0)
    {
        ft_rra(a);
        write(1, "rra\n", 4);
    }
    else if((ft_strcmp(str, "rrb")) == 0)
    {
        ft_rrb(b);
        write(1, "rrb\n", 4);   
    }
    else if((ft_strcmp(str, "rrr")) == 0)
    {
        ft_rrr(a, b);
        write(1, "rrr\n", 4); 
    }
}

