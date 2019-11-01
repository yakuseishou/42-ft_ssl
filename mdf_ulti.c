/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdf_ulti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 01:18:07 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/31 00:25:47 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "mdf.h"

uint32_t	mdf_leftrot(uint32_t f, uint32_t s)
{
	return ((f << s) | (f >> (32 - s)));
}

void		mdf_addback(t_mdf *mdf)
{
	mdf->a0 = mdf->a + mdf->a0;
	mdf->b0 = mdf->b + mdf->b0;
	mdf->c0 = mdf->c + mdf->c0;
	mdf->d0 = mdf->d + mdf->d0;
}

void		mdf_addstart(t_mdf *mdf)
{
	mdf->a = mdf->a0;
	mdf->b = mdf->b0;
	mdf->c = mdf->c0;
	mdf->d = mdf->d0;
}

uint32_t	mdf_swap_bit(uint32_t s)
{
	uint32_t	r;

	r = ((s >> 24) | ((s >> 8) & 0xff00) | ((s << 8) & 0xff0000) | (s << 24));
	return (r);
}

void		mdf_endifix(t_mdf *mdf)
{
	mdf->a0 = mdf_swap_bit(mdf->a0);
	mdf->b0 = mdf_swap_bit(mdf->b0);
	mdf->c0 = mdf_swap_bit(mdf->c0);
	mdf->d0 = mdf_swap_bit(mdf->d0);
}
