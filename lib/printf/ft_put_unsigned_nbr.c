/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:16 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/19 16:38:25 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_unsigned_num(unsigned int n)
{
	size_t	count;

	if (n > 0)
		count = 0;
	else
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_put_unsigned_nbr(unsigned int n)
{	
	unsigned int	num;

	num = n;
	if (num >= 10)
		ft_put_unsigned_nbr(num / 10);
	ft_putchar(num % 10 + '0');
	return (ft_count_unsigned_num(num));
}
