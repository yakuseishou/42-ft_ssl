/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prin_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 00:39:42 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/10 21:31:06 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwhole(long long a, int *store)
{
	ft_putlong(a);
	store[arlen] += ft_numlen(a);
}

void	ft_putfrac(int *store, size_t n, size_t i, long long y)
{
	if (!store[PERC] || store[PercNUM] > 0)
	{
		write(1, ".", 1);
		store[arlen]++;
		ft_putzrfrac(store, n, i, y);
	}
	else if (store[HASH])
	{
		write(1, ".", 1);
		store[arlen]++;
	}
}

void	parti_f(double a, int *store, size_t n, size_t *i)
{
	long long	y;
	long long	x;

	y = 0;
	if (a < 0)
		a = -a;
	x = (long long)a;
	if (!store[PERC] || (store[PercNUM] > 0))
		y = ft_convefrac(a, n, i);
	else if (store[PercNUM] <= 0)
	{
		y = ft_convefrac(a, n, i) / 100000;
		if (y > 4)
			y = 1000000;
	}
	if (ft_numlen(y) > n)
	{
		x += 1;
		plus_ultra(&y, n);
	}
	ft_putwhole(x, store);
	ft_putfrac(store, n, *i, y);
}

void	prin_float(va_list list, int *store)
{
	long long	x;
	size_t		i;
	double		a;
	size_t		n;

	i = 0;
	a = va_arg(list, double);
	x = (long long)a;
	n = 6;
	pad_f(store, &n, x, a);
	parti_f(a, store, n, &i);
	if (store[num] > 0 && store[neg])
	{
		while (store[num]--)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
	}
}
