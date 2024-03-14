/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ss.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:26:03 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/07 14:12:44 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(stack_list **a)
{
    stack_list *temp;
    int swap;
    
    temp = *a;
    if(temp != NULL && temp->next != NULL)
    {
        swap = temp->data;
        temp->data = temp->next->data;
        temp->next->data = swap;
    }
}

void ft_sb(stack_list **b)
{
    stack_list *temp;
    int swap;
    
    temp = *b;
    if(temp != NULL && temp->next != NULL)
    {
        swap = temp->data;
        temp->data = temp->next->data;
        temp->next->data = swap;
    }
}

void ft_ss(stack_list **a, stack_list **b)
{
    ft_sa(a);
    ft_sb(b);
}

void write_inst_swap(stack_list **a, stack_list **b, char *str)
{
    if((ft_strcmp(str, "sa")) == 0)
    {
        ft_sa(a);
        write(1, "sa\n", 3);
    }
    else if((ft_strcmp(str, "sb")) == 0)
    {
        ft_sb(b);
        write(1, "sb\n", 3);   
    }
    else if((ft_strcmp(str, "ss")) == 0)
    {
        ft_ss(a, b);
        write(1, "ss\n", 3); 
    }
}