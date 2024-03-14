/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:42:52 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:15:30 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_max_min_b(stack_list **b, target_node *target)
{
    if (*b == NULL) 
        return;
    stack_list *temp;
    int max_value;
    int min_value;
    
    temp = *b;
    max_value = temp->data;
    min_value = temp->data;
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(temp->data > max_value) 
            max_value = temp->data;
        else if(min_value > temp->data)
            min_value = temp->data;
    }
    target->min_stack_b = min_value;
    target->max_stack_b = max_value;
}

void find_max_min_a(stack_list **a, target_node *target)
{
    if (*a == NULL) 
        return;
    stack_list *temp;
    int max_value;
    int min_value;
    
    temp = *a;
    max_value = temp->data;
    min_value = temp->data;
    while(temp->next != NULL)
    {
        temp = temp->next;
        if(temp->data > max_value) 
            max_value = temp->data;
        else if(min_value > temp->data)
            min_value = temp->data;
    }
    target->min_stack_a = min_value;
    target->max_stack_a = max_value;
}

