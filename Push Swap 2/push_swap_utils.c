/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:40:06 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 11:26:48 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	b;

	if (!dstsize)
		return (ft_strlen(src));
	b = 0;
	while (b < (dstsize - 1) && src[b] != '\0')
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > (slen - start))
		len = (slen - start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
char	*ft_strdup(const char *s1)
{
	char	*b;
	int		a;
	int		c;

	c = ft_strlen(s1);
	a = 0;
	b = ((char *)malloc((c + 1) * (sizeof(char))));
	if (!b)
		return (0);
	while (s1[a] != '\0')
	{
		b[a] = s1[a];
		a++;
	}
	b[a] = '\0';
	return (b);
}

int	lst_len(stack_list **lst)
{
	int	a;
	stack_list *temp;
	
	a = 0;
	temp = *lst;
	while (temp)
	{
		temp= temp->next;
		a++;
	}
	return (a);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while ((s1[n] != '\0' || s2[n] != '\0') && s1[n] == s2[n])
	{
		n++;
	}
	return (s1[n] - s2[n]);
}

int list_position(stack_list **stack, int num)
{
	stack_list *temp;
	int			size;
	int			i;

	i = 0;
	temp = *stack;
	size = lst_len(stack);
	while (i < size)
	{
		if (temp->data == num)
			break ;
		temp= temp->next;
		i++;
	}
	return (i);
}

stack_list	*list_last(stack_list **a)
{
	stack_list *temp;

	temp = *a;
	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}