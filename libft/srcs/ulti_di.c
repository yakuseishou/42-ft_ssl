/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulti_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:14:53 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/08 22:58:12 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	convert_di_b(long long a, int *store)
{
	int			x;
	long int	b;
	long long	res;

	if (store[speci_l])
	{
		b = (long int)a;
		res = (long long)b;
	}
	else if (store[speci_ll])
	{
		res = a;
	}
	else
	{
		x = (int)a;
		res = (long long)x;
	}
	return (res);
}

long long	convert_di(long long a, int *store)
{
	signed char	y;
	short int	z;
	long long	res;

	if (store[speci_h])
	{
		z = (short int)a;
		res = (long long)z;
	}
	else if (store[speci_hh])
	{
		y = (signed char)a;
		res = (long long)y;
	}
	else
		res = convert_di_b(a, store);
	return (res);
}

void		cas_prin_di(int *store, long long a)
{
	if (store[speci_h])
	{
		ft_putlong((short int)a);
		store[arlen] += ft_numlen(a);
	}
	else if (store[speci_hh])
	{
		ft_putlong((signed char)a);
		store[arlen] += ft_numlen(a);
	}
	else if (store[speci_l])
	{
		ft_putlong((long int)a);
		store[arlen] += ft_numlen(a);
	}
	else if (store[speci_ll])
	{
		ft_putlong((long long)a);
		store[arlen] += ft_numlen(a);
	}
	else
	{
		ft_putlong((int)a);
		store[arlen] += ft_numlen(a);
	}
}
