/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:21:14 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/16 16:43:39 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = ft_strnew(len);
	i = 0;
	if (!s)
		return (0);
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
