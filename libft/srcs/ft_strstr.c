/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:10:57 by kchen2            #+#    #+#             */
/*   Updated: 2019/02/14 19:41:06 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i])
	{
		while ((str[i + j] == to_find[j]) && to_find[j])
			j += 1;
		if (to_find[j] == '\0')
			return ((char *)str + i);
		j = 0;
		i += 1;
	}
	return (0);
}
