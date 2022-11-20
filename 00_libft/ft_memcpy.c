/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:20:21 by psotto-m          #+#    #+#             */
/*   Updated: 2022/11/09 15:58:48 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	s = src;
	d = dest;
	i = 0;
	while (i < n)
	{
		((unsigned char *)d)[i] = ((unsigned char *)s)[i];
		i++;
	}
	return (d);
}
