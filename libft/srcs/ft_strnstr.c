/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:47:33 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/15 14:25:42 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s == '\0')
		return ((char *)b);
	i = 0;
	while (i < n && b[i])
	{
		j = 0;
		while (b[i + j] == s[j] && s[j] && i + j < n)
			j++;
		if (s[j] == '\0')
			return ((char *)(b + i));
		i++;
	}
	return (0);
}
