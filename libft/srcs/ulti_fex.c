/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulti_fex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:23:18 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/10 21:55:54 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putzrfrac(int *store, size_t n, size_t i, long long y)
{
	if (i > 0)
	{
		while (i-- > 0 && n > 0)
		{
			write(1, "0", 1);
			n--;
			store[arlen]++;
		}
	}
	if (n > 0)
	{
		ft_putlong(y);
		store[arlen] += ft_numlen(y);
	}
	i = ft_numlen(y) - 1;
	while (++i < n)
	{
		write(1, "0", 1);
		store[arlen]++;
	}
}
