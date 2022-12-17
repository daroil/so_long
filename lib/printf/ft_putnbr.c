/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:13:26 by dhendzel          #+#    #+#             */
/*   Updated: 2022/11/11 05:55:23 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnbr(int n)
{	
	long	num;

	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		ft_printnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

static size_t	ft_count_num(int n)
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

int	ft_putnbr(int n)
{	
	ft_printnbr(n);
	return (ft_count_num(n));
}
