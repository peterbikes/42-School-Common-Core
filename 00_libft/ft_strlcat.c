/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:21:22 by psotto-m          #+#    #+#             */
/*   Updated: 2022/11/06 18:21:24 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dest;

	if (size == 0)
		return (ft_strlen(src));
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	j = len_dest;
	i = 0;
	if (size < len_dest)
		return (len_src + size);
	while (src[i] && j < (size - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
