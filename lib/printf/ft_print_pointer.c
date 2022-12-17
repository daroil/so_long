/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:24:56 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/19 16:43:43 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long ptr)
{
	int		i;
	int		res;
	char	s2[16];

	res = 0;
	i = 15;
	res += ft_putstr("0x");
	if (ptr == 0)
		res += ft_putchar('0');
	while (ptr)
	{
		if ((ptr % 16) >= 10)
			s2[i] = (ptr % 16) + 87;
		else
			s2[i] = (ptr % 16) + '0';
		ptr /= 16;
		i--;
	}
	while (++i < 16)
		res += ft_putchar(s2[i]);
	return (res);
}
