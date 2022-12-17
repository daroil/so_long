/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:17:06 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/19 16:44:19 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int u, char c)
{
	int		i;
	int		j;
	int		res;
	char	s[8];

	res = 0;
	i = 7;
	if (c == 'x')
		j = 87;
	if (c == 'X')
		j = 55;
	if (u == 0)
		res += ft_putchar('0');
	while (u)
	{
		if ((u % 16) >= 10)
			s[i] = (u % 16) + j;
		else
			s[i] = (u % 16) + '0';
		u /= 16;
		i--;
	}
	while (++i < 8)
		res += ft_putchar(s[i]);
	return (res);
}
