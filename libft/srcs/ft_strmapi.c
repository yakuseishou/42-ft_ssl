/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:17:09 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/16 16:49:50 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ns;

	if (!s)
		return (0);
	ns = ft_strnew(ft_strlen(s));
	if (!ns)
		return (0);
	i = -1;
	while (s[++i])
		ns[i] = f(i, s[i]);
	return (ns);
}
