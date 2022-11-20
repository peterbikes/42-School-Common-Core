/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:21:14 by psotto-m          #+#    #+#             */
/*   Updated: 2022/11/06 18:21:16 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	tolen;

	i = 0;
	tolen = (ft_strlen(s1) + ft_strlen(s2));
	string = (char *)malloc(sizeof(char) * tolen + 1);
	if (!string)
		return (NULL);
	while (ft_strlen(s1))
	{
		string[i] = *s1++;
		i++;
	}
	while (ft_strlen(s2))
	{
		string[i] = *s2++;
		i++;
	}
	string[i] = '\0';
	return (string);
}
