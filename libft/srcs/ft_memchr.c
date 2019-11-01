/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:19:53 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/21 14:48:48 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)str;
	while (n--)
	{
		if (*b == (unsigned char)c)
			return (b);
		b++;
	}
	return (0);
}
