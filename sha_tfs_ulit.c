/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_tfs_ulit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:09:38 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/31 16:31:29 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

void		shatfs_value_init(t_sha256 *shatfs)
{
	shatfs->h0 = 0x6a09e667;
	shatfs->h1 = 0xbb67ae85;
	shatfs->h2 = 0x3c6ef372;
	shatfs->h3 = 0xa54ff53a;
	shatfs->h4 = 0x510e527f;
	shatfs->h5 = 0x9b05688c;
	shatfs->h6 = 0x1f83d9ab;
	shatfs->h7 = 0x5be0cd19;
}

void		sha256_addstart(t_sha256 *tfs)
{
	tfs->a = tfs->h0;
	tfs->b = tfs->h1;
	tfs->c = tfs->h2;
	tfs->d = tfs->h3;
	tfs->e = tfs->h4;
	tfs->f = tfs->h5;
	tfs->g = tfs->h6;
	tfs->h = tfs->h7;
}

void		sha256_addback(t_sha256 *tfs)
{
	tfs->h0 += tfs->a;
	tfs->h1 += tfs->b;
	tfs->h2 += tfs->c;
	tfs->h3 += tfs->d;
	tfs->h4 += tfs->e;
	tfs->h5 += tfs->f;
	tfs->h6 += tfs->g;
	tfs->h7 += tfs->h;
}

uint32_t	rr_32(uint32_t w, uint32_t r)
{
	return (((w >> r) | (w << (32 - r))));
}

uint32_t	swap_32b(uint32_t r)
{
	return (((r >> 24) & 0xff) | ((r << 8) & 0xff0000) |
		((r >> 8) & 0xff00) | ((r << 24) & 0xff000000));
}
