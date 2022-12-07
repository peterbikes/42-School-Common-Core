/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:36:46 by psotto-m          #+#    #+#             */
/*   Updated: 2022/12/04 17:36:47 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putpointer(unsigned long long n)
{
	unsigned int	size;

	size = 2;
	if (!n)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	if (n < 16)
	{
		size += write(1, &"0123456789abcdef"[n], 1);
	}
	if (n >= 16)
	{
		size += ft_puthexalocase (n / 16);
		size += ft_puthexalocase (n % 16);
	}
	return (size);
}
