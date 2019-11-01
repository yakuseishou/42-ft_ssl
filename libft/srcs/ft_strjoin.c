/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:48:43 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/24 21:49:55 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;

	if (!s1 || !s2)
		return (0);
	if (!(ns = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	ft_strcpy(ns, s1);
	ft_strcat(ns, s2);
	return (ns);
}
