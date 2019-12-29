/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:15:40 by geliz             #+#    #+#             */
/*   Updated: 2019/12/29 19:15:56 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define hh_ -10
# define h_ -11
# define ll_ -12
# define l_ -13
# define char_ -14
# define char_null_ -140
# define L_ -141
# define str_ -15
# define ptr_ -16
# define int_ -17
# define oct_ -18
# define flt_ -19
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_info
{
	int			minus;
	int			plus;
	int			space;
	int			octotorp;
	int			zero;
	int			flag;
	int			width;
	int			precision;
	int			size;
	int			content;
	int			unsign;
	int			base;
	int			error;
}					t_info;

typedef union 		u_float
{
	double			d;
	struct			s_bit
	{
		unsigned long int	mantissa	: 52;
        unsigned long int	exponent	: 11;
        unsigned int		sign		: 1;
	}				t_bit;
}					t_float;

typedef union		u_lfloat
{
	long double		ld;
	struct			s_lbit
	{
		unsigned long int	mantissa	: 64;
        unsigned long int	exponent	: 15;
        unsigned int		sign		: 1;	
	}				t_lbit;
}					t_lfloat;

int		ft_printf(const char *c, ...);
t_info	*ft_create_info(t_info *in);
int		ft_print_base(const char *c, int i);
int		ft_readstring(int i, t_info *info, const char *c);
int		ft_flags(const char *c, int i, t_info *info);
int		ft_width(const char *c, int i, t_info *info);
int		ft_precision(const char *c, int i, t_info *info);
int		ft_size(const char *c, int i, t_info *info);
int		ft_content(const char *c, int i, t_info *info);
int		ft_print_content(t_info *in, va_list ap);
char    *ft_apply_info_to_string(t_info *in, va_list ap);
char	*ft_string_null(char *str);
char    *ft_precision_to_string(t_info *in, char *str, int prec);
char    *ft_width_to_string(t_info *in, char *str);
char    *ft_width_with_minus(t_info *in, char *str, char *ret);
char    *ft_width_without_minus(t_info *in, char *str, char *ret);
char	*ft_apply_info_to_char(t_info *in, va_list ap);
int     ft_print_char_null_with_width(t_info *in, char *str);
int     ft_char_null_width_minus(t_info *in);
int     ft_char_null_width_plus(t_info *in);
char    *ft_apply_info_to_int(t_info *in, va_list ap);
char	*ft_convert_int_to_str(t_info *in, va_list ap);
char	*ft_convert_sized_int_to_str(t_info *in, va_list ap);
char	*ft_convert_unsigned_sized_int_to_str(t_info *in, va_list ap);
char	*ft_convert_unsigned_sized_h_hh_int_to_str(t_info *in, va_list ap);
char	*ft_convert_sized_h_hh_int_to_str(t_info *in, va_list ap);
char	*ft_unsigned_ll_itoa_base(unsigned long long int n, int base);
char	*ft_ll_itoa(long long int n);
char	*ft_precision_to_int(t_info *in, char *ret);
char	*ft_precision_to_int_with_minus(t_info *in, char *ret, int len);
int		ft_is_nmb_zero(t_info *in, char *ret);
char	*ft_plus_to_int(char *ret);
char	*ft_space_to_int(t_info *in, char *ret);
char	*ft_width_to_int(t_info *in, char *ret);
char	*ft_width_with_minus_to_int(t_info *in, char *ret);
char	*ft_width_with_zero_to_int(t_info *in, char *ret);
char	*ft_width_with_space_to_int(t_info *in, char *ret);
char	*ft_apply_info_to_oct(t_info *in, va_list ap);
char	*ft_octotorp_to_int(t_info *in, char *ret);

char	*ft_width_with_zero_to_hexadec_int(t_info *in, char *temp, char *ret, int len);
char	*ft_precision_to_int_base_hexadec(t_info *in, char *ret, int len);

char	*ft_apply_info_to_flt(t_info *in, va_list ap);

char	*ft_apply_exp_to_mantissa(char *temp, int exp, int sign, int plus);
char	*ft_negative_power_to_mant(char *mant, int j, int pow);
void	ft_fill_array_with_zero(char res[310], char temp[310]);
char	*ft_array_to_string(char arr[310]);
void	ft_summ_strings(char res[310], char temp[310]);
char	*ft_add_divis_to_integ(char *integ, char *divis, int sign, int plus);

char	*ft_keys_width_prec_to_float(t_info *in, char *nbr);
char	*ft_width_to_float(t_info *in, char *str);

char	*ft_precision_float_zero(char *nbr, int i, t_info *in);

char	*ft_precision_more_add_zero(char *nbr, int len, int af_dot, int prec);
char	*ft_precision_less_cut_str(char *nbr, int len, int prec);

char	*ft_keys_space_to_float(t_info *in, char *nbr);

char	*ft_width_to_inf_or_nan(t_info *in, char *str);
char	*ft_keys_to_inf(t_info *in, char *ret, unsigned int sign);

char	*ft_apply_info_to_flt_long(t_info *in, va_list ap);

int		ft_binary_str_to_int(char *temp);

# include <stdio.h>
#endif
