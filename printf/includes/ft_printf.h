/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:15:40 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 22:24:27 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define hh_ -10
# define h_ -11
# define ll_ -12
# define l_ -13
# define L_ -14
# define percent_ -15
# define char_ -16
# define char_null_ -160
# define str_ -17
# define ptr_ -18
# define int_ -19
# define oct_ -20
# define flt_ -21
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

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
		unsigned long long int	mantissa	: 64;
        unsigned long int	exponent	: 15;
        unsigned int		sign		: 1;	
	}				t_lbit;
}					t_lfloat;

/*
ft_printf_hub.c
*/
int		ft_printf(const char *c, ...);
t_info	*ft_create_info(t_info *in);
int		ft_print_base(const char *c, int i);
int		ft_readkeys_and_type(int i, t_info *info, const char *c);
/*
readkeys.c
*/
int		ft_flags(const char *c, int i, t_info *info);
int		ft_width(const char *c, int i, t_info *info);
int		ft_precision(const char *c, int i, t_info *info);
int		ft_size(const char *c, int i, t_info *info);
int		ft_content(const char *c, int i, t_info *info);
/*
check_and_print_content.c
*/
int		ft_check_and_print_content(t_info *in, va_list ap);
int		ft_print_string_and_check_null(t_info *in, char *str);
/*
type_percent.c
*/
char	*ft_apply_info_to_percent(t_info *in);
/*
type_char.c
*/
char	*ft_apply_info_to_char(t_info *in, va_list ap);
int     ft_print_char_null_with_width(t_info *in, char *str);
int     ft_char_null_width_minus(t_info *in);
int     ft_char_null_width_plus(t_info *in);
/*
type_string.c
*/
char    *ft_apply_info_to_string(t_info *in, va_list ap);
char    *ft_precision_to_string(t_info *in, char *str);
char    *ft_width_to_string(t_info *in, char *str);
char    *ft_width_with_minus(t_info *in, char *str, char *ret);
char    *ft_width_without_minus(t_info *in, char *str, char *ret);
/*
type_ptr.c
*/
char	*ft_apply_info_to_ptr(t_info *in, va_list ap);
char	*ft_precision_to_ptr(t_info *in, char *ret);
char	*ft_width_to_ptr(t_info *in, char *ret);
/*
type_int.c
*/
char    *ft_apply_info_to_int(t_info *in, va_list ap);
char	*ft_precision_to_int(t_info *in, char *ret);
char	*ft_precision_to_int_negative(t_info *in, char *ret, int len);
int		ft_is_nmb_zero(t_info *in, char *ret);
char	*ft_plus_to_int(char *ret);
/*
type_int_convert_to_str.c
*/
char	*ft_convert_int_to_str(t_info *in, va_list ap);
char	*ft_convert_sized_int_to_str(t_info *in, va_list ap);
char	*ft_convert_unsigned_sized_int_to_str(t_info *in, va_list ap);
char	*ft_convert_unsigned_sized_h_hh_int_to_str(t_info *in, va_list ap);
char	*ft_convert_sized_h_hh_int_to_str(t_info *in, va_list ap);
/*
type_int_base.c
*/
char	*ft_octotorp_to_int(t_info *in, char *ret);
char	*ft_octotorp_to_o(char *str, size_t len);
char	*ft_octotorp_to_x_small(char *str, size_t len);
char	*ft_octotorp_to_x_big(char *str, size_t len);
/*
type_int_hexadec.c
*/
char	*ft_precision_to_int_base_hexadec(t_info *in, char *ret, int len);
char	*ft_width_with_zero_to_hexadec_int(t_info *in, char *temp, char *ret, int len);
/*
type_int_width_and_space.c
*/
char	*ft_space_to_int(t_info *in, char *ret);
char	*ft_width_to_int(t_info *in, char *ret);
char	*ft_width_with_minus_to_int(t_info *in, char *ret);
char	*ft_width_with_zero_to_int(t_info *in, char *ret);
char	*ft_width_with_space_to_int(t_info *in, char *ret);
/*
ft_unsigned_ll_itoa_base_hub.c
*/
char	*ft_unsigned_ll_itoa_base(unsigned long long int n, int base);
/*
ft_unsigned_ll_itoa_base.c
*/
int		ft_intlen(unsigned long long int n, int base);
char	*ft_convert_deci(unsigned long long int n, int i);
char	*ft_convert_octal(unsigned long long int n, int i);
char	*ft_convert_hexadec(unsigned long long int n, int i);
char	*ft_convert_binary(unsigned long long int n, int i);
/*
ft_ll_itoa.c
*/
char	*ft_ll_itoa(long long int n);
/*
type_float.c
*/
char	*ft_apply_info_to_flt(t_info *in, va_list ap);
char	*ft_check_nan_and_inf(t_info *in, t_float d);
int		ft_binary_str_to_int(char *temp);
int		ft_count_square(char c, int j);
char	*ft_add_zero_and_hidden_to_mant(char *temp, int exp);
/*
type_float_keys_to_spec.c
*/
char	*ft_keys_to_inf(t_info *in, char *ret, unsigned int sign);
char	*ft_width_to_inf_or_nan(t_info *in, char *str);
/*
type_float_mant_count.c
*/
char	*ft_apply_exp_to_mantissa(char *mant, int pow, int sign, t_info *in);
void	ft_fill_array_with_zero(char res[25000], char temp[25000]);
void	ft_power_to_two(char temp[25000], int pow);
void	ft_summ_strings(char res[25000], char temp[25000]);
char	*ft_array_to_string(char arr[25000]);
/*
type_float_neg_powers.c
*/
char	*ft_negative_power_to_mant(char *mant, int j, int pow);
void	ft_negative_power(char temp[25000], int pow);
void	ft_neg_pow_cycle(char temp[25000]);
void	ft_reverse_array(char arr[25000]);
void	ft_summ_divis_strings(char res[25000], char temp[25000]);
/*
type_float_check_parts.c
*/
char	*ft_add_divis_to_integ(char *integ, char *divis, int sign, t_info *in);
char	*ft_check_integ(char *integ);
/*
type_float_apply_info.c
*/
char	*ft_keys_width_prec_to_float(t_info *in, char *nbr);
char	*ft_precision_to_float(t_info *in, char *nbr);
/*
type_float_apply_prec_zero.c
*/
char	*ft_precision_float_zero(char *nbr, int i, t_info *in);
int		ft_precision_zero_round_up(char *nbr, int i, int pos);
/*
type_float_apply_prec_not_zero.c
*/
char	*ft_precision_more_add_zero(char *nbr, int len, int af_dot, int prec);
char	*ft_precision_less_cut_str(char *nbr, int len, int prec);
char	*ft_precision_round_up_integ_part(char *nbr, int len, int prec);
int		ft_precision_round_up_integ_part_ost(char *nbr, int len, int pos);
/*
type_float_apply_width.c
*/
char	*ft_width_to_float(t_info *in, char *str);
char	*ft_width_with_minus_to_float(t_info *in, char *str);
char	*ft_width_without_minus_to_float(t_info *in, char *str);
/*
type_float_apply_plus_space.c
*/
char	*ft_keys_space_to_float(t_info *in, char *nbr);




char	*ft_width_to_inf_or_nan(t_info *in, char *str);
char	*ft_keys_to_inf(t_info *in, char *ret, unsigned int sign);

char	*ft_apply_info_to_flt_long(t_info *in, va_list ap);

int		ft_binary_str_to_int(char *temp);



int			ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(char c);
char	*ft_strcat(char *s1, const char *s2);
void	ft_strdel(char **as);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
int		ft_toupper(int c);


//char	*ft_apply_info_to_oct(t_info *in, va_list ap);


# include <stdio.h>
#endif
