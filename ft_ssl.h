/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:19:49 by kchen2            #+#    #+#             */
/*   Updated: 2019/11/01 01:11:57 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <strings.h>
# include <errno.h>

# include "libft/srcs/libft.h"
# include "libft/srcs/get_next_line.h"
# include "libft/srcs/ft_printf.h"
# include "mdf.h"
# include "sha256.h"

typedef struct	s_hash
{
	char		*key;
	void		(*func)(uint8_t*, size_t);
}				t_table;

typedef enum
{
	PASS = 0,
	QUIET = 1,
	REVERSE = 2,
	SUM = 3,
	ST = 4,
	FILES = 5,
	ERR = 6,
	TOTAL = 7
}	t_flag;

/*
**  ft_sll.c
*/

int				main(int ac, char **av);
int				error_s(int *flags, char *av);
int				error_check(int ac, char *s);
void			check_filename(int i, char ac, char **av, int *flags);
int				error_invalid_cmd(char *s);

/*
**  flags.c
*/

int				error_flags(char c, char *av);
int				valid_flags(char *s, int i, int *flags, char *av);
int				check_flags(char *s, int *flags, char *av);
int				flag_init(int *i, int ac, int *flags, char **av);

/*
**  dis_table.c
*/

void			prin_head(char *av, int *flags, char *s, char *n);
void			prin_tail(char *av, int *flags, char *n);
void			hash_table(int *flags, char *s, char *av, char *fname);

/*
**  prin_file.c
*/

void			error_file(int *flags, char *cmd, char *av, int fd);
void			prin_file(int *flags, char *str, char *av, char *s);
int				valid_file(char *s, int *flags, char *av);

/*
**  prin_in.c
*/

void			prin_null(int *flags, char *av);
int				run_stdin(int *flags, char *av);

/*
**  mdf.c
*/

void			mdf_prin(t_mdf *mdf);
void			mdf_arg(uint32_t *msg, t_mdf *mdf);
void			mdf_trans(t_mdf *mdf);
void			mdf_padding(uint8_t *s, size_t len, t_mdf *mdf);
void			init_mdf(u_int8_t *s, size_t len);

/*
**  mdf_ulti.c
*/

uint32_t		mdf_leftrot(uint32_t f, uint32_t s);
void			mdf_addback(t_mdf *mdf);
void			mdf_addstart(t_mdf *mdf);
uint32_t		mdf_swap_bit(uint32_t s);
void			mdf_endifix(t_mdf *mdf);

/*
**  sha_tfs.c
*/

void			sha256_arg(t_sha256 *tfs, int i);
void			sha256_in(t_sha256 *tfs, int chunk);
void			sha256_chunk(t_sha256 *shatfs);
void			sha256_padding(uint8_t *s, size_t len, t_sha256 *shatfs);
void			init_sha_tfs(u_int8_t *s, size_t len);

/*
**  sha_tfs_ulit.c
*/

void			shatfs_value_init(t_sha256 *shatfs);
void			sha256_addstart(t_sha256 *tfs);
void			sha256_addback(t_sha256 *tfs);
uint32_t		rr_32(uint32_t w, uint32_t r);
uint32_t		swap_32b(uint32_t r);

/*
**  sha_tfs_prin.c
*/

void			sha256_prin(t_sha256 *tfs);

#endif
