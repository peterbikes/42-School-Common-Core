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

unsigned int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	nbr;
	unsigned int	size;

	size = 0;
	if (n < 0)
	{
		nbr = (4294967295 - n) + 1;
		size = ft_putnbr(nbr);
	}
	else
		size = ft_putnbr(n);
	return (size);
}
