/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:17:54 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/01 01:17:17 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_ulti.h"

int		error_invalid_cmd(char *s)
{
	write(1, "ft_ssl: Error: '", 16);
	ft_putstr(s);
	write(1, "' is an invalid command.\n\n", 27);
	write(1, "Standard commands:\n\n", 21);
	write(1, "Message Digest commands:\nmd5\n", 30);
	write(1, "sha256\n\nCipher commands:\n", 26);
	return (1);
}

int		error_check(int ac, char *s)
{
	int		flag;
	int		i;

	i = -1;
	flag = 0;
	if (ac < 2)
	{
		write(1, "usage: ft_ssl command [command opts] [command args]\n", 53);
		return (1);
	}
	while (++i < C_TOTAL)
	{
		if (!strcmp(g_hash[i].key, s))
		{
			flag = 1;
			break ;
		}
	}
	if (flag == 0)
		return (error_invalid_cmd(s));
	return (0);
}

int		error_s(int *flags, char *av)
{
	if (flags[ST])
	{
		ft_putstr(av);
		write(1, ": option requires an argument -- s\nusage: ", 43);
		ft_putstr(av);
		write(1, " [-pqrtx] [-s string] [files ...]\n", 35);
		return (0);
	}
	return (1);
}

void	check_filename(int i, char ac, char **av, int *flags)
{
	int		r;

	r = 0;
	flags[FILES] = 1;
	while (i < ac)
	{
		r = valid_file(av[i], flags, av[1]);
		if (flags[ERR])
			error_file(flags, av[1], av[i], r);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		flags[TOTAL];

	i = 1;
	ft_bzero(flags, sizeof(int) * TOTAL);
	if (error_check(ac, av[1]))
		return (0);
	if (!flag_init(&i, ac, flags, av))
		return (0);
	if (!error_s(flags, av[1]))
		return (0);
	if (ac < 3 || flags[PASS])
	{
		run_stdin(flags, av[1]);
		flags[FILES] = 1;
	}
	if (av[i])
		check_filename(i, ac, av, flags);
	if (!flags[FILES] && !flags[SUM])
		run_stdin(flags, av[1]);
	return (0);
}
