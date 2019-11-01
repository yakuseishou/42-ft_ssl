/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:53:38 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/16 16:51:42 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*ns;

	if (!s)
		return (0);
	ns = ft_strnew(ft_strlen(s));
	if (!ns)
		return (0);
	i = 0;
	while (s[i])
	{
		ns[i] = f(s[i]);
		i++;
	}
	return (ns);
}
