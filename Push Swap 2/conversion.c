/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:40:13 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:15:19 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_for_error(char *str)
{
    int a;
    
    a = 0;
    while(str[a])
    {
        if((str[a] == '-' || str[a] == '+') && (!(str[a + 1] >= '0' && str[a + 1] <= '9')))
            return (1);
        if((str[a] >= 33 && str[a] < 43) || str[a] == 44 || (str[a] >= 46 && str[a] <= 47) 
            || (str[a] >= 58 && str[a] <= 126))
            return (1);
        if((str[a] >= 9 && str[a] <= 13) || (str[a] == '\n'))
            return (1);
        a++;
    }
    a = 0;
    if(str[a] >= '0' && str[a] <= '9')
    {
        while(str[a++])
        {
            if(str[a] == '-' || str[a] == '+')
                return (1);
        }
    }
    return (0);
}

stack_list *convert_list(stack_list **a, int num)
{
    stack_list *node;
    stack_list *temp;

    node = (stack_list *)malloc(sizeof(stack_list));
    if(!node)
        return (NULL);
    node->data = num;
    node->next = NULL;
    
    if(*a == NULL)   
        *a = node; 
    else
    {
        temp = *a;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
    return (node);
}

int search_duplicates(stack_list *list , int num)
{
	stack_list *temp;
    
    temp = list;
    while(temp != NULL)
    {
        if(temp->data == num)
            return (1);
        temp = temp->next;
    }
    return (0);
}

stack_list *create_stack(stack_list **a, char **str)
{
	int num;
	stack_list *list;
    int b;
	
    b = 0;
    while(str[b])
    {
        if((check_for_error(str[b])))
            return (NULL);
        b++;
    }
    b = 0;
	while(str[b])
	{
        num = conv_num(str[b]);
	    if(search_duplicates(*a, num))
            if(list != NULL)
                ft_free_list(&list);
        list = convert_list(a, num);
        b++;
    }
    ft_handle_free(str);
    return (list);
}
 