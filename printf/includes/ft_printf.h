/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:15:40 by geliz             #+#    #+#             */
/*   Updated: 2019/11/17 17:19:19 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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
int		ft_check_cont(t_info *in, va_list ap);
int		ft_print_string(t_info *in, va_list ap);
char	*ft_string_null(char *str);
int		ft_string_flag(t_info *in, int i, int j, char *str);
void	ft_print_list_temp(t_info *info);

# include <stdio.h>
#endif
