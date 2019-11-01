/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulti_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:11:38 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/10 21:58:21 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pad_f(int *store, size_t *n, long long x, double a)
{
	if (store[PercNUM])
		*n = store[PercNUM];
	store[num] -= ft_numlen(x);
	if (store[PercNUM] > 0)
		store[num] -= *n;
	if (store[num] > 0 && (!store[PERC] || store[PercNUM] > 0))
		store[num]--;
	else if (store[num] > 0 && store[HASH])
		store[num]--;
	if (a < 0 && store[num] > 0)
		store[num]--;
	if (a >= 0 && store[pos] && store[num] > 0)
		store[num]--;
	prin_f_lpad(store, a);
}

void		prin_f_lpad(int *store, double a)
{
	if (!store[pos] && store[space] && a >= 0)
	{
		write(1, " ", 1);
		store[arlen]++;
		if (store[num] > 0)
			store[num]--;
	}
	if (store[num] > 0 && !store[neg] && !store[zero])
	{
		while (store[num] > 0)
		{
			write(1, " ", 1);
			store[num]--;
			store[arlen]++;
		}
	}
	prin_f_signzero(store, a);
}

void		prin_f_signzero(int *store, double a)
{
	if (a < 0)
	{
		write(1, "-", 1);
		store[arlen]++;
	}
	if (a >= 0 && store[pos])
	{
		write(1, "+", 1);
		store[arlen]++;
	}
	while (store[num] > 0 && !store[neg] && store[zero])
	{
		write(1, "0", 1);
		store[num]--;
		store[arlen]++;
	}
}

void		plus_ultra(long long *y, size_t n)
{
	long long	l;
	size_t		i;

	l = 1;
	i = -1;
	while (++i < n)
		l *= 10;
	*y %= l;
}

long long	ft_convefrac(double a, size_t n, size_t *j)
{
	size_t		i;
	long long	x;
	double		b;

	i = -1;
	x = (long long)a;
	b = a;
	a -= x;
	while (++i < (n + 1))
	{
		b *= 10;
		if ((long long)b % 10 != 0)
			break ;
		*j += 1;
	}
	if (*j > n)
		*j = n;
	i = -1;
	while (++i < (n + 1))
		a *= 10;
	x = (long long)a;
	(x % 10 > 4) ? (x += 10) : 0;
	x /= 10;
	return (x);
}
