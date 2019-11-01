/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:42:55 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/08 21:53:05 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*itoa_base(long long int num, int base, int flag)
{
	char	alloc[50];
	char	*res;
	int		i;
	int		neg;

	neg = 1;
	res = (flag == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	if (num == 0)
		return (ft_strdup("0"));
	i = 48;
	alloc[49] = '\0';
	if (num < 0)
		neg = -1;
	while (num != 0)
	{
		alloc[i--] = res[neg * (num % base)];
		num /= base;
	}
	return (ft_strdup(&(alloc[++i])));
}
