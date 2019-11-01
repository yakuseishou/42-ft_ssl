/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:37:52 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/08 22:00:09 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putlong(long long n)
{
	long long	min;

	min = -9223372036854775808U;
	if (n == min)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n < 0 && n > min)
		n *= -1;
	if (n >= 10)
	{
		ft_putlong(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}
