/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchen2 <kchen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:03:07 by kchen2            #+#    #+#             */
/*   Updated: 2019/10/25 23:18:45 by kchen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef	enum
{
	dataint = 0,
	datadec = 1,
	dataoctal = 2,
	datahex = 3,
	datahexcap = 4,
	datachar = 13,
	datastr = 14,
	dataptr = 15,
	dataFLOAT = 22,
}	t_datatype;

typedef	enum
{
	speci_h = 5,
	speci_hh = 6,
	speci_l = 7,
	speci_ll = 8,
	speci_Lcap = 16
}	t_speci;

typedef	enum
{
	pos = 9,
	neg = 10,
	space = 11,
	zero = 12,
	num = 17,
	FLAGS = 18,
	HASH = 19
}	t_flags;

typedef	enum
{
	PERC = 20,
	PercNUM = 21,
	arlen = 23
}	t_perc;

int			ft_printf(const char *s, ...);
int			prin_nonflag(va_list list, const char *s);
void		prin_perc(int *store);
void		prin_flag(va_list list, const char *s, int *store, size_t i);
void		prin_perce(va_list list, const char *s, int *store, size_t i);
void		check_data(va_list list, int *store);
/*
** function for store keys
*/
void		store_flags(int *store, char c);
void		store_speci(int *store, const char *s, int i, int l);
void		store_datatype(int *store, char c);
/*
** s & c print
*/
void		prin_char(va_list list, int *store);
void		prin_str(const char *s, int *store);
void		str_pad(va_list list, int *store);
/*
** function for d & i
*/
void		pad_di(va_list list, int *store);
void		print_di(int *store, long long x);
void		print_di_zpad(int *store, long long x);
void		print_di_lpad(int *store, long long x);
long long	convert_di_b(long long a, int *store);
long long	convert_di(long long a, int *store);
void		cas_prin_di(int *store, long long a);
/*
** ouxX
*/
void		prin_num(va_list list, int *store, int base);
void		pad_num(long long a, int *store, int l);
void		prin_num_lpad(long long a, int *store);
void		prin_num_head(long long a, int *store);
void		prin_num_zpad(long long a, int *store);
void		prin_num_zpad_b(long long a, int *store);
void		prin_num_value(long long a, int *store, int base, int l);
/*
** float
*/
void		prin_float(va_list list, int *store);
long long	ft_convefrac(double a, size_t n, size_t *j);
void		pad_f(int *store, size_t *n, long long x, double a);
void		parti_f(double a, int *store, size_t n, size_t *i);
void		ft_putfrac(int *store, size_t n, size_t i, long long y);
void		ft_putzrfrac(int *store, size_t n, size_t i, long long y);
void		prin_f_lpad(int *store, double a);
void		prin_f_signzero(int *store, double a);
void		ft_putwhole(long long a, int *store);
void		plus_ultra(long long *y, size_t n);
/*
** L float
*/
void		prin_lfloat(va_list list, int *store);
long long	ft_lconvefrac(long double a, size_t n, size_t *j);
void		pad_lf(int *store, size_t *n, long long x, long double a);
void		parti_lf(long double a, int *store, size_t n, size_t *i);
void		prin_lf_lpad(int *store, long double a);
void		prin_lf_signzero(int *store, long double a);

#endif
