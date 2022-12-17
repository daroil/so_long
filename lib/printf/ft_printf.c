/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:02:32 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/19 17:03:38 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_flag(va_list argptr, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(argptr, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(argptr, int)));
	if (c == 'u')
		return (ft_put_unsigned_nbr(va_arg(argptr, int)));
	if (c == 's')
		return (ft_putstr(va_arg(argptr, char *)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'x' || c == 'X')
		return (ft_print_hexa(va_arg(argptr, unsigned int), c));
	if (c == 'p')
		return (ft_print_pointer(va_arg(argptr, unsigned long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		add;

	add = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
			add += ft_handle_flag(argptr, *(++str));
		else
			add += ft_putchar(*str);
		str++;
	}
	va_end(argptr);
	return (add);
}
