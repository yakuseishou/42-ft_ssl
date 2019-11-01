/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:33:50 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/15 16:36:16 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	n;

	n = ft_strlen(src);
	res = (char*)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (0);
	n = 0;
	while (src[n])
	{
		res[n] = src[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}
