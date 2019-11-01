/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:45:37 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/14 21:57:21 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*b;
	unsigned char	*c;
	size_t			i;

	i = 0;
	b = (unsigned char *)str1;
	c = (unsigned char *)str2;
	while (i < n)
	{
		if (b[i] != c[i])
			return (b[i] - c[i]);
		i++;
	}
	return (0);
}
