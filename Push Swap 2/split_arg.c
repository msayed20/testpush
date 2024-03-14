/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:51:18 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/09 20:02:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char const *s)
{
	int	counter;
	int	a;
	int	still_word;

	a = 0;
	counter = 0;
	while (s[a])
	{
		still_word = 0;
		while (s[a] == 32)
			a++;
		while (s[a] != 32 && s[a])
		{
			if (still_word == 0)
			{
				counter++;
				still_word = 1;
			}
			a++;
		}
	}
	return (counter);
}

void	ft_free_word(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free (spl[i]);
		i++;
	}
	free (spl);
}

char	*get_word(char const *s)
{
	int	a;

	a = 0;
	while (s[a] != 32 && s[a])
		a++;
	return (ft_substr(s, 0, a));
}

char	**split_arg(char const *s)
{
	char	**str;
	int		a;
	int		b;
	int		size;

	if (!s)
		return (NULL);
	a = 0;
	b = 0;
	size = count_words(s) + 1;
	str = malloc(sizeof(char *) * (size));
	if (!str)
		return (NULL);
	while (s[a] && b < size - 1)
	{
		while (s[a] && s[a] == 32)
			a++;
		str[b++] = get_word((s + a));
		if (!str[b - 1])
			return (ft_free_word(str), NULL);
		while (s[a] && s[a] != 32)
			a++;
	}
	str[b] = NULL;
	return (str);
}
