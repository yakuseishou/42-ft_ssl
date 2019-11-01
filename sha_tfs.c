/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_tfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:21:19 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/31 16:29:36 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

void	sha256_arg(t_sha256 *tfs, int i)
{
	uint32_t	ch;
	uint32_t	maj;
	uint32_t	s0;
	uint32_t	s1;

	sha256_addstart(tfs);
	while (++i < 64)
	{
		s1 = (rr_32(tfs->e, 6) ^ rr_32(tfs->e, 11) ^ rr_32(tfs->e, 25));
		ch = ((tfs->e & tfs->f) ^ ((~tfs->e) & tfs->g));
		tfs->t1 = tfs->h + s1 + ch + g_sha256_k[i] + tfs->w[i];
		s0 = (rr_32(tfs->a, 2) ^ rr_32(tfs->a, 13) ^ rr_32(tfs->a, 22));
		maj = (tfs->a & tfs->b) ^ (tfs->a & tfs->c) ^ (tfs->b & tfs->c);
		tfs->t2 = s0 + maj;
		tfs->h = tfs->g;
		tfs->g = tfs->f;
		tfs->f = tfs->e;
		tfs->e = tfs->d + tfs->t1;
		tfs->d = tfs->c;
		tfs->c = tfs->b;
		tfs->b = tfs->a;
		tfs->a = tfs->t1 + tfs->t2;
	}
	sha256_addback(tfs);
}

void	sha256_in(t_sha256 *tfs, int chunk)
{
	int			i;
	uint32_t	s0;
	uint32_t	s1;

	tfs->w = (uint32_t *)malloc(sizeof(uint32_t) * 64 * 8);
	ft_bzero(tfs->w, sizeof(uint32_t) * 64 * 8);
	ft_memcpy(tfs->w, &(tfs->msg[16 * chunk]), 16 * 32);
	i = 15;
	while (++i < 64)
	{
		s0 = (rr_32(tfs->w[i - 15], 7)\
		^ (rr_32(tfs->w[i - 15], 18) ^ (tfs->w[i - 15] >> 3)));
		s1 = (rr_32(tfs->w[i - 2], 17)\
		^ (rr_32(tfs->w[i - 2], 19)) ^ (tfs->w[i - 2] >> 10));
		tfs->w[i] = tfs->w[i - 16] + s0 + tfs->w[i - 7] + s1;
	}
}

void	sha256_chunk(t_sha256 *shatfs)
{
	int			chunk;

	chunk = 0;
	shatfs_value_init(shatfs);
	while (chunk < shatfs->len)
	{
		sha256_in(shatfs, chunk);
		sha256_arg(shatfs, -1);
		free(shatfs->w);
		chunk += 1;
	}
}

void	sha256_padding(uint8_t *s, size_t len, t_sha256 *shatfs)
{
	uint32_t	l;
	int			i;

	i = -1;
	l = len * 8 + 1;
	while (l % 512 != 488)
		l++;
	shatfs->len = (l + 64) / 512;
	if (!(shatfs->msg = malloc(sizeof(uint32_t) * 16 * shatfs->len)))
		return ;
	ft_bzero(shatfs->msg, sizeof(uint32_t) * 16 * shatfs->len);
	ft_memcpy((char *)shatfs->msg, s, len);
	((char *)shatfs->msg)[len] = 0x80;
	while (++i < (shatfs->len * 16))
		shatfs->msg[i] = swap_32b((uint32_t)shatfs->msg[i]);
	shatfs->msg[(shatfs->len * 512 - 64) / 32 + 1] = (uint32_t)len * 8;
}

void	init_sha_tfs(u_int8_t *s, size_t len)
{
	t_sha256	shatfs;

	ft_bzero(&shatfs, sizeof(t_sha256));
	sha256_padding(s, len, &shatfs);
	sha256_chunk(&shatfs);
	sha256_prin(&shatfs);
	ft_memdel((void **)&(shatfs.msg));
}
