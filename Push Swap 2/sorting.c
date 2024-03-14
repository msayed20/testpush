/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:38 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:21:41 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(stack_list **a)
{
    stack_list *list;
    
    list = *a;
    if (list->next != NULL && list->data < list->next->data)
    {
        list = list->next;    
        while (list->next != NULL && (list->data < list->next->data))
        {
            if(!((list->data < list->next->data)))
                break;
            list = list->next;
            if(list->next == NULL)
                return (1);
        }
    }
    return (0);
}

stack_list *ft_sort(stack_list **a, stack_list **b)
{
    int length;
    
    length = lst_len(a);
    if(!a)
        return (NULL);
    if((ft_is_sorted(a)))
       return (*a); 
    if(length == 2)
        ft_sa(a);
    else if(length == 3)
        sort_three(a, b);
    else if(length == 4)
        sort_four(a, b);
    else if (length > 4)
        sort_multi(a, b);
    return(*a);
}
