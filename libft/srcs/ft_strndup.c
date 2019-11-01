/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:09:05 by kchen2            #+#    #+#             */
/*   Updated: 2019/06/26 21:29:36 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (0);
	i = -1;
	while (++i < n)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}
