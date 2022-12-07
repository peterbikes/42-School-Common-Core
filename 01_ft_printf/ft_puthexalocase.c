/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexalocase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:36:12 by psotto-m          #+#    #+#             */
/*   Updated: 2022/12/04 17:36:13 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_puthexalocase(long long int n)
{
	unsigned int	size;

	size = 0;
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
