/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:10:28 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/18 16:00:40 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (n < i)
		return (n + j);
	a = 0;
	while (src[a] && (i + a + 1) < n)
	{
		dst[i + a] = src[a];
		a++;
	}
	dst[i + a] = 0;
	return (i + j);
}
