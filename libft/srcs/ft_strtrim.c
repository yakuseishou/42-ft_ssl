/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:07:59 by kchen2            #+#    #+#             */
/*   Updated: 2019/05/15 15:24:20 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = ft_strlen(s);
	while (ft_ispace(s[i]) == 1)
		i++;
	while (ft_ispace(s[i]) == 1)
		n--;
	if (n < i)
		n = i;
	res = ft_strnew(n - i);
	if (!res)
		return (0);
	return (ft_strncpy(res, &s[i], n - i));
}
