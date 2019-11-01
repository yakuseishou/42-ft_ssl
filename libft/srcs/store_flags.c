/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:33:26 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/08 22:25:52 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_flags(int *store, char c)
{
	if (c == '+')
		store[pos]++;
	else if (c == '-')
		store[neg]++;
	else if (c == ' ')
		store[space]++;
	else if (c == '#')
		store[HASH]++;
	else if (c == '0')
		store[zero]++;
}

void	store_speci(int *store, const char *s, int i, int l)
{
	if (s[i] == 'h')
	{
		if (i < l && s[i + 1] == 'h')
			store[speci_hh]++;
		else
			store[speci_h]++;
	}
	else if (s[i] == 'l')
	{
		if (i < l && s[i + 1] == 'l')
			store[speci_ll]++;
		else
			store[speci_l]++;
	}
	else if (s[i] == 'L')
		store[speci_Lcap]++;
}

void	store_datatype(int store[20], char c)
{
	if (c == 'd' || c == 'i')
		store[dataint]++;
	else if (c == 'u')
		store[datadec]++;
	else if (c == 'o')
		store[dataoctal]++;
	else if (c == 'x')
		store[datahex]++;
	else if (c == 'X')
		store[datahexcap]++;
	else if (c == 'c')
		store[datachar]++;
	else if (c == 's')
		store[datastr]++;
	else if (c == 'p')
		store[dataptr]++;
	else if (c == 'f')
		store[dataFLOAT]++;
}
