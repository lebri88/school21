/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:29:03 by geliz             #+#    #+#             */
/*   Updated: 2019/12/02 17:43:04 by geliz            ###   ########.fr       */
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
	in->error = 0;
	return (in);
}
///*
void	ft_print_list_temp(t_info *info)
{
	write(1, "\nminus = ", 9);
	ft_putnbr(info->minus);
	write(1, "\nplus = ", 8);
	ft_putnbr(info->plus);
	write(1, "\nspace = ", 9);
	ft_putnbr(info->space);
	write(1, "\noctot = ", 9);
	ft_putnbr(info->octotorp);
	write(1, "\nzero = ", 8);
	ft_putnbr(info->zero);
	write(1, "\nflag = ", 8);
	ft_putnbr(info->flag);
	write(1, "\nwidth = ", 9);
	ft_putnbr(info->width);
	write(1, "\nprecis = ", 10);
	ft_putnbr(info->precision);
	write(1, "\nsize = ", 8);
	if (info->size == 0)
		ft_putchar('0');
	if (info->size == hh)
		ft_putstr("hh");
	if (info->size == h)
		ft_putchar('h');
	if (info->size == ll)
		ft_putstr("ll");
	if (info->size == l)
		ft_putchar('l');
//	ft_putnbr(info->size);
	write(1, "\ncont = ", 8);
	ft_putnbr(info->content);
	write(1, "\n", 1);
}
//*/

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
//		ft_print_list_temp(info);
		free (info);
	}
	return (res);
}
