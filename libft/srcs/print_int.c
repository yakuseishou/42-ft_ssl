/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:50:39 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/10 17:55:40 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di(int *store, long long x)
{
	if (x != 0)
		cas_prin_di(store, x);
	else if (!store[PERC])
		cas_prin_di(store, x);
	if (store[num] > 0 && store[neg])
	{
		while (store[num]--)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
		if (store[PERC] && !store[PercNUM] && x == 0)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
	}
}

void	print_di_zpad(int *store, long long x)
{
	while (store[num] > 0 && !store[neg] && store[zero] && !store[PERC])
	{
		write(1, "0", 1);
		store[num]--;
		store[arlen]++;
	}
	if (store[PERC] && store[PercNUM] > 0)
	{
		while (store[PercNUM]-- > 0)
		{
			write(1, "0", 1);
			store[arlen]++;
		}
		if (x == 0)
		{
			write(1, "0", 1);
			store[arlen]++;
		}
	}
	print_di(store, x);
}

void	print_di_lpad(int *store, long long x)
{
	if (store[num] > 0 && !store[neg] && !store[zero])
	{
		while (store[num] > 0)
		{
			write(1, " ", 1);
			store[arlen]++;
			store[num]--;
		}
		if (store[PERC] && !store[PercNUM] && x == 0)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
	}
	if (x < 0)
	{
		write(1, "-", 1);
		store[arlen]++;
	}
	if (x >= 0 && store[pos])
	{
		write(1, "+", 1);
		store[arlen]++;
	}
	print_di_zpad(store, x);
}

void	pad_di(va_list list, int *store)
{
	long long	x;

	x = convert_di(va_arg(list, long long), store);
	store[num] -= ft_numlen(x);
	if (x < 0 && store[num] > 0)
		store[num]--;
	if (x >= 0 && store[pos] && store[num] > 0)
		store[num]--;
	if (!store[pos] && store[space] && x >= 0)
	{
		write(1, " ", 1);
		store[arlen]++;
		(store[num] > 0) ? store[num]-- : 0;
	}
	if (store[PERC])
	{
		if (store[PercNUM] > (int)ft_numlen(x))
			store[PercNUM] -= ft_numlen(x);
		else
			store[PercNUM] = 0;
		if (store[num] > 0 && store[PercNUM] > 0)
			store[num] -= store[PercNUM];
		store[zero] = 0;
	}
	print_di_lpad(store, x);
}
