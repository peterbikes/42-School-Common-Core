/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:42:17 by psotto-m          #+#    #+#             */
/*   Updated: 2022/12/06 22:42:18 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

unsigned int	ft_putnbr(long long int n);
unsigned int	ft_putnbr_unsigned(unsigned int n);
unsigned int	ft_putchar(char c);
unsigned int	ft_putstr(char *s);
unsigned int	ft_puthexaupcase(long long int n);
unsigned int	ft_puthexalocase(long long int n);
unsigned int	ft_putpointer(unsigned long long n);
int				ft_printf(const char *str, ...);

#endif
