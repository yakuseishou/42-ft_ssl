/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prin_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:15:44 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/01 19:52:15 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_num(long long a, int *store, int l)
{
	if (store[PERC])
	{
		if (store[PercNUM] > l)
			store[PercNUM] -= l;
		else
			store[PercNUM] = 0;
		if (store[num] > 0 && store[PercNUM] > 0)
			store[num] -= store[PercNUM];
		store[zero] = 0;
	}
	if (store[num] > 0 && (store[dataptr] || (a != 0 && store[HASH]
		&& (store[datahex] || store[datahexcap]))))
		store[num] -= 2;
	if (store[PercNUM] <= 0 && store[num] > 0 && store[HASH]
		&& store[dataoctal] && a != 0)
		store[num]--;
	if (store[PercNUM] > 0 && store[PERC] && store[HASH] && a == 0
		&& !store[datahex] && !store[datahexcap])
		store[PercNUM]--;
	if (store[PercNUM] <= 0 && store[num] > 0 && store[PERC]
		&& store[HASH] && a == 0 && !store[datahex] && !store[datahexcap])
		store[num]--;
	prin_num_lpad(a, store);
}

void	prin_num_lpad(long long a, int *store)
{
	if (store[num] > 0 && !store[neg] && !store[zero])
	{
		while (store[num] > 0)
		{
			write(1, " ", 1);
			store[num]--;
			store[arlen]++;
		}
		if (store[PERC] && !store[PercNUM] && a == 0)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
	}
	prin_num_head(a, store);
}

void	prin_num_head(long long a, int *store)
{
	if (store[HASH] && store[datahexcap] && a != 0)
	{
		ft_putstr("0X");
		store[arlen] += 2;
	}
	if (store[HASH] && store[datahex] && a != 0)
	{
		ft_putstr("0x");
		store[arlen] += 2;
	}
	if (store[dataptr])
	{
		ft_putstr("0x");
		store[arlen] += 2;
	}
	prin_num_zpad(a, store);
}

void	prin_num_value(long long a, int *store, int base, int l)
{
	char	*s;
	
	if (a != 0 || !store[PERC])
	{
		s = itoa_base(a, base, store[datahexcap]);
		ft_putstr(s);
		free(s);
		store[arlen] += l;
	}
	if (store[num] > 0 && store[neg])
	{
		while (store[num]--)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
		if (store[PERC] && !store[PercNUM] && a == 0)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
	}
}

void	prin_num(va_list list, int *store, int base)
{
	long long	x;
	long long	a;
	int			l;

	a = va_arg(list, long long);
	x = a;
	l = 0;
	if (x == 0)
		l++;
	while (x > 0)
	{
		x /= base;
		l++;
	}
	store[num] -= l;
	pad_num(a, store, l);
	prin_num_value(a, store, base, l);
}
