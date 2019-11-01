/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulti_lf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:15:10 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/10 21:58:22 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pad_lf(int *store, size_t *n, long long x, long double a)
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
	prin_lf_lpad(store, a);
}

void		prin_lf_lpad(int *store, long double a)
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
	prin_lf_signzero(store, a);
}

void		prin_lf_signzero(int *store, long double a)
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

long long	ft_lconvefrac(long double a, size_t n, size_t *j)
{
	size_t		i;
	long long	x;
	long double	b;

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
