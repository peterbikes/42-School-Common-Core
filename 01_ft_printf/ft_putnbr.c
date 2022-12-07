/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:36:30 by psotto-m          #+#    #+#             */
/*   Updated: 2022/12/04 17:36:32 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr(long long int n)
{
	unsigned int	nbr;
	unsigned int	size;

	size = 0;
	if (n < 0)
	{
		size += ft_putchar('-');
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		size += ft_putnbr(nbr / 10);
	}
	size += ft_putchar((char)(nbr % 10 + '0'));
	return (size);
}
