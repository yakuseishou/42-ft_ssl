/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prin_num_zpad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 00:13:01 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/09 00:17:25 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prin_num_zpad_b(long long a, int *store)
{
	if (store[PERC] && store[HASH] && a == 0
		&& !store[datahex] && !store[datahexcap])
	{
		write(1, "0", 1);
		store[arlen]++;
	}
	if (store[PERC] && store[PercNUM] > 0)
	{
		while (store[PercNUM]-- > 0)
		{
			write(1, "0", 1);
			store[arlen]++;
		}
		if (a == 0)
		{
			write(1, "0", 1);
			store[arlen]++;
		}
	}
}

void	prin_num_zpad(long long a, int *store)
{
	while (store[num] > 0 && !store[neg] && store[zero] && !store[PERC])
	{
		write(1, "0", 1);
		store[num]--;
		store[arlen]++;
	}
	if (store[HASH] && store[dataoctal] && a != 0)
	{
		ft_putchar('0');
		store[arlen]++;
		if (store[PercNUM] > 0)
			store[PercNUM]--;
	}
	prin_num_zpad_b(a, store);
}
