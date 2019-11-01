/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:02:44 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/10 23:55:03 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prin_flag(va_list list, const char *s, int *store, size_t i)
{
	if (s[i] == '+' || s[i] == '-' || s[i] == ' ' || s[i] == '#')
		store_flags(store, s[i]);
	else if (!store[num] && !store[PERC] && !store[zero] && s[i] == '0')
		store_flags(store, s[i]);
	else if (s[i] == 'l' || s[i] == 'h' || s[i] == 'L')
		store_speci(store, s, i, ft_strlen(s) - 1);
	else if (!store[PERC] && !store[num] && s[i] >= '0' && s[i] <= '9')
		store[num] = ft_atoi(s + i);
	else if (s[i] == '.')
		store[PERC]++;
	else if (!store[PercNUM] && store[PERC] && s[i] >= '0' && s[i] <= '9')
		store[PercNUM] = ft_atoi(s + i);
	else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
		|| s[i] == 'x' || s[i] == 'X' || s[i] == 'c' || s[i] == 's'
		|| s[i] == 'p' || s[i] == 'f')
	{
		store_datatype(store, s[i]);
		check_data(list, store);
		ft_bzero(store, sizeof(int) * arlen);
	}
}

void	prin_perce(va_list list, const char *s, int *store, size_t i)
{
	if (s[i] == '%')
	{
		prin_perc(store);
		ft_bzero(store, sizeof(int) * arlen);
	}
	else
		prin_flag(list, s, store, i);
}

int		prin_nonflag(va_list list, const char *s)
{
	size_t	i;
	int		store[arlen + 1];

	i = -1;
	ft_bzero(store, sizeof(store));
	while (++i < ft_strlen(s))
	{
		if (!store[FLAGS])
		{
			if (s[i] != '%')
			{
				write(1, &s[i], 1);
				store[arlen]++;
			}
			else
				store[FLAGS]++;
		}
		else
			prin_perce(list, s, store, i);
	}
	return (store[arlen]);
}

int		ft_printf(const char *s, ...)
{
	va_list	list;
	int		res;

	va_start(list, s);
	res = prin_nonflag(list, s);
	va_end(list);
	return (res);
}
