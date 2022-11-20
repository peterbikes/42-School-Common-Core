/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:13:19 by psotto-m          #+#    #+#             */
/*   Updated: 2022/11/13 19:31:39 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlength(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*final;
	int		len;

	len = getlength(n);
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	final[len] = '\0';
	if (n < 0)
		final[0] = '-';
	else if (n == 0)
		final[0] = '0';
	while (n != 0)
	{
		--len;
		final[len] = value(n % 10) + '0';
		n = n / 10;
	}
	return (final);
}
