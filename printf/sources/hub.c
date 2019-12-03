/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:29:03 by geliz             #+#    #+#             */
/*   Updated: 2019/12/03 20:03:47 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_print_base(const char *c, int i)
{
	int		j;

	j = 0;
	while (c[i + j] != '\0')// && c[i + j] != '%')
	{
		if (c[i + j] == '%' && c[i + j + 1] != '%')
			return (j);
		if (c[i + j] == '%')
			i++;
		ft_putchar(c[i + j]);
		j++;
	}
	return (j);
}

int		ft_readstring(int i, t_info *info, const char *c)
{
	while (c[i] != '\0' && c[i] != '%')
		i++;
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
			i = ft_content(c, i, info);
		}
	}
	return (i);
}

t_info	*ft_create_info(t_info *in)
{
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
	in->error = 0;
	return (in);
}

int		ft_printf(const char *c, ...)
{
	t_info		*info;
	int			i;
	va_list		ap;
	int			res;

	i = 0;
	res = 0;
	info = NULL;
	va_start(ap, c);
	while (c[i] != '\0')
	{
		if (!(info = ft_create_info(info)))
			return (-1);
		res = res + ft_print_base(c, i);
		i = ft_readstring(i, info, c);
		res = res + ft_print_content(info, ap);
		free (info);
	}
	return (res);
}
