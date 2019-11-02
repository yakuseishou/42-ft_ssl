/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:20:26 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/01 19:11:18 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "mdf.h"

void	mdf_prin(t_mdf *mdf)
{
	mdf_endifix(mdf);
	ft_printf("%08x%08x%08x%08x", mdf->a0, mdf->b0, mdf->c0, mdf->d0);
}

void	mdf_arg(uint32_t *msg, t_mdf *mdf)
{
	uint32_t	i;
	uint32_t	f;
	uint32_t	tmp;

	i = 0;
	mdf_addstart(mdf);
	while (i < 64)
	{
		if (i < 16)
			f = (mdf->b & mdf->c) | ((~mdf->b) & mdf->d);
		else if (i > 15 && i < 32)
			f = (mdf->d & mdf->b) | ((~mdf->d) & mdf->c);
		else if (i > 31 && i < 48)
			f = mdf->b ^ mdf->c ^ mdf->d;
		else if (i > 47 && i < 64)
			f = mdf->c ^ (mdf->b | (~mdf->d));
		tmp = mdf->d;
		mdf->d = mdf->c;
		mdf->c = mdf->b;
		mdf->b = mdf->b + mdf_leftrot(f + mdf->a +\
				g_md5_k[i] + msg[g_md5_m[i]], g_md5_s[i]);
		mdf->a = tmp;
		i++;
	}
	mdf_addback(mdf);
}

void	mdf_trans(t_mdf *mdf)
{
	uint32_t	chunk;

	chunk = 0;
	while (chunk < mdf->msg_len)
	{
		mdf_arg((uint32_t *)(mdf->msg + chunk), mdf);
		chunk += 64;
	}
}

void	mdf_padding(uint8_t *s, size_t len, t_mdf *mdf)
{
	size_t	i;

	mdf->a0 = 0x67452301;
	mdf->b0 = 0xefcdab89;
	mdf->c0 = 0x98badcfe;
	mdf->d0 = 0x10325476;
	mdf->msg_len = len * 8 + 1;
	while (mdf->msg_len % 512 != 448)
		mdf->msg_len++;
	if (!(mdf->msg = ft_memalloc(mdf->msg_len + 64)))
		return ;
	ft_strcpy((char *)mdf->msg, (const char *)s);
	mdf->msg_len /= 8;
	i = len;
	mdf->msg[i] = 128;
	while (++i < mdf->msg_len)
		mdf->msg[i] = 0;
	*(uint32_t*)(mdf->msg + i) = (uint32_t)len * 8;
}

void	init_mdf(uint8_t *s, size_t len)
{
	t_mdf	mdf;

	ft_bzero(&mdf, sizeof(t_mdf));
	mdf_padding(s, len, &mdf);
	mdf_trans(&mdf);
	mdf_prin(&mdf);
	ft_memdel((void **)&(mdf.msg));
}
