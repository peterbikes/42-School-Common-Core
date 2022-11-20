/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:23:35 by psotto-m          #+#    #+#             */
/*   Updated: 2022/11/16 18:39:39 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parts(const char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (i);
}

static char	*part_dup(const char *str, int start, int finish)
{
	char	*part;
	int		i;

	i = 0;
	part = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		part[i++] = str[start++];
	part[i] = '\0';
	return (part);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((parts(s, c) + 1) * sizeof(char *));
	if (!split | !s)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = part_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
