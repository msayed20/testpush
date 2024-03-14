/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:15:29 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/07 14:11:47 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(stack_list **a)
{
    int swap;
    stack_list *temp;

    temp = *a;
    if(temp != NULL && temp->next != NULL)
    {
        swap = temp->data;
        while(temp->next != NULL)
        {
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->data = swap;
    }
}

void ft_rb(stack_list **b)
{
    int swap;
    stack_list *temp;

    temp = *b;
    if(temp != NULL && temp->next != NULL)
    {
        swap = temp->data;
        while(temp->next != NULL)
        {
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp->data = swap;
    }
}

void ft_rr(stack_list **a, stack_list **b)
{
    ft_ra(a);
    ft_rb(b);
}

void write_inst_rotate(stack_list **a, stack_list **b, char *str)
{
    if((ft_strcmp(str, "ra")) == 0)
    {
        ft_ra(a);
        write(1, "ra\n", 3);
    }
    else if((ft_strcmp(str, "rb")) == 0)
    {
        ft_rb(b);
        write(1, "rb\n", 3);   
    }
    else if((ft_strcmp(str, "rr")) == 0)
    {
        ft_rr(a, b);
        write(1, "rr\n", 3); 
    }
}