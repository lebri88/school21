/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:15:40 by geliz             #+#    #+#             */
/*   Updated: 2019/11/23 20:07:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define hh -10
# define h -11
# define ll -12
# define l -13
# define char_ -14
# define str_ -15
# define ptr_ -16
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

# include <stdio.h>
#endif
