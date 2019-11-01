/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:17:24 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/31 00:10:04 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_ulti.h"

void	prin_head(char *av, int *flags, char *s, char *n)
{
	size_t	i;
	char	*tmp;

	i = -1;
	tmp = ft_strnew(sizeof(av));
	ft_strcpy(tmp, av);
	if (n && !flags[REVERSE] && !flags[QUIET])
	{
		while (++i < ft_strlen(tmp))
			if (tmp[i] >= 'a' && tmp[i] <= 'z')
				tmp[i] -= 32;
		ft_putstr(tmp);
		write(1, " (", 3);
		if (flags[SUM])
			write(1, "\"", 1);
		if (!flags[FILES])
			ft_putstr(s);
		else
			ft_putstr(n);
		if (flags[SUM])
			write(1, "\"", 1);
		write(1, ") = ", 5);
	}
	free(tmp);
}

void	prin_tail(char *av, int *flags, char *n)
{
	if (av && flags[REVERSE] && !flags[QUIET])
	{
		write(1, " ", 1);
		if (flags[SUM])
			write(1, "\"", 1);
		if (!flags[FILES])
			ft_putstr(av);
		else
			ft_putstr(n);
		if (flags[SUM])
			write(1, "\"", 1);
	}
	write(1, "\n", 1);
}

void	hash_table(int *flags, char *s, char *av, char *fname)
{
	int		i;

	i = -1;
	prin_head(av, flags, s, fname);
	while (++i < C_TOTAL)
	{
		if (!strcmp(g_hash[i].key, av))
		{
			g_hash[i].func((uint8_t *)s, ft_strlen(s));
			break ;
		}
	}
	prin_tail(s, flags, fname);
}
