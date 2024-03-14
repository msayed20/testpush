/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:04:19 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:04:19 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_overflow(int result, int sign, char a)
{
	if ((a == '+' && result == '+') || (a == '-' && result == '-')) 
	{
        write(2, "Error\n", 6);
        exit(1);
    }
	if (sign == 1)
	{
		if ((result == INT_MAX / 10 && a >= '7') || result > INT_MAX / 10)
			return (1);
	}
	else if (sign == -1)
	{
		if ((result == INT_MAX / 10 && a >= '8') || result > INT_MAX / 10)
			return (1);
	}
	return (0);
}


int	conv_num(const char *str)
{
	int	sign;
	int	result;
    int a;

	sign = 1;
	result = 0;
    a = 0;
	while (str[a] == 32 || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-')
		sign *= -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
    while (str[a] >= '0' && str[a] <= '9')
	{
        if((check_for_overflow(result, sign, str[a])))
        {
            write(2, "Error\n", 6);
            exit(1);
        }   
		result = result * 10 + str[a] - '0';
		a++;
	}
	return ((result * sign));
}






