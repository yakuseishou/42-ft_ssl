/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prin_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 00:54:55 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/01 01:17:46 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_ulti.h"

void	prin_null(int *flags, char *av)
{
	while (flags[PASS] > 1)
	{
		flags[PASS]--;
		hash_table(flags, "\0", av, NULL);
	}
}

int		run_stdin(int *flags, char *av)
{
	int		ret;
	char	*temp;
	char	*str;
	char	buff[2];

	str = ft_strnew(1);
	ret = 0;
	buff[1] = '\0';
	while ((ret = read(0, buff, 1)) > 0)
	{
		if (ret == 0)
			break ;
		temp = str;
		str = ft_strjoin(temp, buff);
		free(temp);
	}
	if (flags[PASS])
		ft_putstr(str);
	hash_table(flags, str, av, NULL);
	free(str);
	if (flags[PASS] > 1)
		prin_null(flags, av);
	return (1);
}
