/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_ulti.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 00:05:25 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/31 16:38:47 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_ULTI_H
# define FT_SSL_ULTI_H

# include "ft_ssl.h"

typedef enum
{
	C_TOTAL = 2
}	t_hash;

static t_table	g_hash[C_TOTAL] =
{
	{ "md5", &init_mdf },
	{ "sha256", &init_sha_tfs }
};

static t_table	g_hash[];

#endif
