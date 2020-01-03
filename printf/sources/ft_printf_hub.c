/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:29:03 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 14:44:58 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_readkeys_and_type(int i, t_info *info, const char *c)
{
	if (c[i] == '%')
	{
		while (info->content == 0)
		{
			i++;
			i = ft_flags(c, i, info);
			if ((i = ft_width(c, i, info)) == 0)
				return (-1);
			if ((i = ft_precision(c, i, info)) == 0)
				return (-1);
			i = ft_size(c, i, info);
			if ((i = ft_content(c, i, info)) == 0)
				return (-1);
		}
	}
	return (i);
}

int		ft_print_base(const char *c, int i)
{
	int		j;
	char	*str;

	j = 0;
	while (c[i + j] != '%' && c[i + j] != '\0')
		j++;
	if (j != 0)
	{
		str = ft_strsub(c, i, j);
		write(1, str, j);
		ft_strdel(&str);
	}
	return (j);
}

t_info	*ft_create_info(t_info *in)
{
	if (!in)
		in = malloc(sizeof(t_info) * 1);
	in->minus = 0;
	in->plus = 0;
	in->space = 0;
	in->octotorp = 0;
	in->zero = 0;
	in->flag = 0;
	in->width = -1;
	in->precision = -1;
	in->size = 0;
	in->content = 0;
	in->unsign = 0;
	in->base = 'd';
	in->error = 0;
	return (in);
}

int		ft_printf(const char *c, ...)
{
	t_info		*info;
	va_list		ap;
	int			i;
	int			j;
	int			res;

	i = 0;
	res = 0;
	info = NULL;
	va_start(ap, c);
	while (c[i] != '\0')
	{
		if (!(info = ft_create_info(info)))
			return (-1);
		j = ft_print_base(c, i);
		res += j;
		i += j;
		if ((i = ft_readkeys_and_type(i, info, c)) == -1)
			return (0);
		res = res + ft_check_and_print_content(info, ap);
	}
	free(info);
	return (res);
}
