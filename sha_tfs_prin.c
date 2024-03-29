/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_tfs_prin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:01:42 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/31 16:32:04 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"
#include "ft_ssl.h"

void	sha256_prin(t_sha256 *tfs)
{
	ft_printf("%08x%08x%08x%08x", tfs->h0, tfs->h1, tfs->h2, tfs->h3);
	ft_printf("%08x%08x%08x%08x", tfs->h4, tfs->h5, tfs->h6, tfs->h7);
}
