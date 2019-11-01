/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:19:28 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/30 22:45:46 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		error_flags(char c, char *av)
{
	ft_putstr(av);
	write(1, ": illegal option -- ", 21);
	write(1, &c, 1);
	write(1, "\nusage: ", 9);
	ft_putstr(av);
	write(1, " [-pqrtx] [-s string] [files ...]\n", 35);
	return (-1);
}

int		valid_flags(char *s, int i, int *flags, char *av)
{
	while (s[i])
	{
		if (s[i] == 'p')
			flags[PASS]++;
		else if (s[i] == 's')
		{
			flags[SUM]++;
			if (s[i + 1] != '\0')
				hash_table(flags, s + i + 1, av, "Y");
			else
				flags[ST]++;
			break ;
		}
		else if (s[i] == 'r')
			flags[REVERSE]++;
		else if (s[i] == 'q')
			flags[QUIET]++;
		else
			return (error_flags(s[i], av));
		i++;
	}
	return (0);
}

int		check_flags(char *s, int *flags, char *av)
{
	size_t	i;
	int		r;

	i = 0;
	r = 0;
	if (!s)
		return (0);
	if (s[i] != '-' && !flags[ST])
		return (0);
	if (flags[ST])
	{
		flags[ST]--;
		hash_table(flags, s, av, "Y");
	}
	else if (s[i] == '-')
	{
		i++;
		if (!s[i])
			return (0);
		r = valid_flags(s, i, flags, av);
		if (r == -1)
			return (-1);
	}
	return (1);
}

int		flag_init(int *i, int ac, int *flags, char **av)
{
	int		r;

	r = 0;
	while (++(*i) < ac)
	{
		r = check_flags(av[*i], flags, av[1]);
		if (!r)
			break ;
		else if (r == -1)
			return (0);
	}
	return (1);
}
