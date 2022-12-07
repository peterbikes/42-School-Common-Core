/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:36:59 by psotto-m          #+#    #+#             */
/*   Updated: 2022/12/06 22:37:01 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(const char *str_char, va_list args)
{
	unsigned int	result;

	result = 0;
	if (*str_char == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (*str_char == 'u')
		result += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*str_char == 'd' || *str_char == 'i')
		result += ft_putnbr(va_arg(args, int));
	else if (*str_char == '%')
		result += write(1, "%", 1);
	else if (*str_char == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (*str_char == 'x')
		result += ft_puthexalocase(va_arg(args, unsigned int));
	else if (*str_char == 'X')
		result += ft_puthexaupcase(va_arg(args, unsigned int));
	else if (*str_char == 'p')
		result += ft_putpointer(va_arg(args, unsigned long long));
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	result;

	if (!str)
		return (0);
	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result += ft_flags(&str[i + 1], args);
			i++;
		}
		else
			result += write(1, &str[i], 1);
	i++;
	}
	va_end(args);
	return (result);
}
