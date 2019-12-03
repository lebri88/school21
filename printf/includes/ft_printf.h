/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:15:40 by geliz             #+#    #+#             */
/*   Updated: 2019/12/03 20:20:04 by geliz            ###   ########.fr       */
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
# define str_ -15
# define ptr_ -16
# define int_ -17
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
	int			error;
}					t_info;

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
char	*ft_precision_to_int(t_info *in, char *ret, int len);
char	*ft_precision_to_int_with_minus(t_info *in, char *ret, int len);
char	*ft_plus_to_int(char *ret);
char	*ft_space_to_int(t_info *in, char *ret);
char	*ft_width_to_int(t_info *in, char *ret);
char	*ft_width_with_minus_to_int(t_info *in, char *ret);
char	*ft_width_with_zero_to_int(t_info *in, char *ret);
char	*ft_width_with_space_to_int(t_info *in, char *ret);
char	*ft_apply_info_to_sized_int(t_info *in, va_list ap);
char	*ft_long_long_itoa(long long int n);
char	*ft_apply_info_to_long_int(t_info *in, va_list ap);
char	*ft_apply_info_to_long_long_int(t_info *in, va_list ap);
char	*ft_apply_info_to_short_int(t_info *in, va_list ap);
char	*ft_apply_info_to_int_hh_char(t_info *in, va_list ap);
char	*ft_apply_info_to_unsigned_long_int(t_info *in, va_list ap);
char	*ft_apply_info_to_unsigned_long_long_int(t_info *in, va_list ap);
char	*ft_unsigned_long_long_itoa(unsigned long long int n);
char	*ft_apply_info_to_unsigned_short_int(t_info *in, va_list ap);
char	*ft_apply_info_to_int_hh_unsigned_char(t_info *in, va_list ap);
char	*ft_apply_info_to_unsigned_int(t_info *in, va_list ap);
# include <stdio.h>
#endif
