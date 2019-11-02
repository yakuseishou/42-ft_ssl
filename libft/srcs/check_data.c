/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:43:35 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/01 19:47:25 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_data(va_list list, int *store)
{
	if (store[datachar])
		prin_char(list, store);
	else if (store[datastr])
		str_pad(list, store);
	else if (store[dataint])
		pad_di(list, store);
	else if (store[datadec])
		prin_num(list, store, 10);
	else if (store[dataoctal])
		prin_num(list, store, 8);
	else if (store[datahex] || store[datahexcap])
		prin_num(list, store, 16);
	else if (store[dataptr])
		prin_num(list, store, 16);
	else if (store[dataFLOAT])
	{
		if (store[speci_Lcap])
			prin_lfloat(list, store);
		else
			prin_float(list, store);
	}
}

void	prin_char(va_list list, int *store)
{
	char	c;

	c = (const char)va_arg(list, int);
	if (!store[neg])
	{
		while (--store[num] > 0)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
	}
	store[arlen]++;
	ft_putchar(c);
	if (store[neg])
	{
		while (--store[num] > 0)
		{
			write(1, " ", 1);
			store[arlen]++;
		}
	}
}

void	prin_str(const char *s, int *store)
{
	while (store[num] > 0 && !store[neg])
	{
		write(1, " ", 1);
		store[num]--;
		store[arlen]++;
	}
	if (store[PERC] && (int)ft_strlen(s) > store[PercNUM])
	{
		write(1, s, store[PercNUM]);
		store[arlen] += store[PercNUM];
	}
	else
	{
		ft_putstr(s);
		store[arlen] += ft_strlen(s);
	}
	while (store[num] > 0 && store[neg])
	{
		write(1, " ", 1);
		store[num]--;
		store[arlen]++;
	}
}

void	str_pad(va_list list, int *store)
{
	const char	*s;

	s = va_arg(list, char*);
	if (s)
	{
		if (store[PERC] && (int)ft_strlen(s) > store[PercNUM])
			store[num] -= store[PercNUM];
		else
			store[num] -= ft_strlen(s);
	}
	if (s == NULL)
	{
		s = "(null)";
		if (store[PERC] && 6 > store[PercNUM])
			store[num] -= store[PercNUM];
		else
			store[num] -= 6;
	}
	prin_str(s, store);
}

void	prin_perc(int store[19])
{
	store[num]--;
	while (store[num] > 0 && !store[neg] && !store[zero])
	{
		write(1, " ", 1);
		store[num]--;
		store[arlen]++;
	}
	while (store[num] > 0 && !store[neg] && store[zero])
	{
		write(1, "0", 1);
		store[num]--;
		store[arlen]++;
	}
	write(1, "%", 1);
	store[arlen]++;
	while (store[num] > 0 && store[neg])
	{
		write(1, " ", 1);
		store[num]--;
		store[arlen]++;
	}
}
