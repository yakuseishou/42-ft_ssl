/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:34:59 by kchen2            #+#    #+#             */
/*   Updated: 2019/03/11 20:11:19 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*c;
	char	*b;
	size_t	i;

	i = 0;
	c = (char *)s2;
	b = (char *)s1;
	if (c < b)
		while ((int)(--n) >= 0)
			*(b + n) = *(c + n);
	else
		while (i < n)
		{
			b[i] = c[i];
			i++;
		}
	return (s1);
}
