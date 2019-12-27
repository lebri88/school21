/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readkeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:08:33 by geliz             #+#    #+#             */
/*   Updated: 2019/12/27 22:17:56 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_content(const char *c, int i, t_info *in)
{
	if (c[i] == 'c')
		in->content = char_;
	if (c[i] == 's')
		in->content = str_;
	if (c[i] ==  'p')
		in->content = ptr_;
	if (c[i] == 'i' || c[i] == 'd')
		in->content = int_;
	if (c[i] == 'u')
	{
		in->content = int_;
		in->unsign = 1;
	}
	if (c[i] == 'o' || c[i] == 'x' || c[i] == 'X')
	{
		in->content = int_;
		in->base = (int)c[i];
	}
	if (c[i] == 'f')
		in->content = flt_;
	in->content == 0 ? i = 0 : i++;
//	if (in->content != 0)
//		i++;
	return (i);
}

int		ft_size(const char *c, int i, t_info *in)
{
	if (in->size == 0)
	{
		if (c[i] == 'h' && c[i + 1] == 'h')
			in->size = hh_;
		if (c[i] == 'h' && in->size == 0)
			in->size = h_;
		if (c[i] == 'l' && c[i + 1] == 'l')
			in->size = ll_;
		if (c[i] == 'l' && in->size == 0)
			in->size = l_;
		if (c[i] == 'L' && in->size == 0)
			in->size = L_;
	}
	if (in->size == hh_ || in->size == ll_)
		return (i + 2);
	if (in->size == h_ || in->size == l_)
		return (i + 1);
	return (i);
}

int		ft_precision(const char *c, int i, t_info *in)
{
	char	*prec;
	int		j;

	j = 0;
	if (in->precision == -1)
	{
		if (c[i] == '.')
		{
			i++;
			while (c[i + j] >= '0' && c[i + j] <= '9')
				j++;
			in->flag = 1;
			if (j == 0)
				in->precision = 0;
			else
			{	
				if (!(prec = ft_strsub(c, i, j)))
					return (0);
				in->precision = ft_atoi(prec);
				ft_strdel(&prec);
			}
			i = i + j;
		}
	}
	return (i);
}

int		ft_width(const char *c, int i, t_info *in)
{
	char	*wid;
	int		j;

	j = 0;
	if (in->width == -1)
	{
		if (c[i] >= '1' && c[i] <= '9')
		{
			while (c[i + j] >= '0' && c[i + j] <= '9')
				j++;
			in->flag = 1;
			if (!(wid = ft_strsub(c, i, j)))
				return (0);
			in->width = ft_atoi(wid);
			ft_strdel(&wid);
			i = i + j;
		}
	}
	return (i);
}

int		ft_flags(const char *c, int i, t_info *in)
{
	if (in->flag == 0)
	{
		while (c[i] == '-' || c[i] == '+' || c[i] == ' ' ||
				c[i] == '#' || c[i] == '0')
		{
			if (c[i] == '-')
				in->minus = 1;
			if (c[i] == '+')
				in->plus = 1;
			if (c[i] == ' ')
				in->space = 1;
			if (c[i] == '#')
				in->octotorp = 1;
			if (c[i] == '0')
				in->zero = 1;
			i++;
			in->flag = 1;
		}
	}
	return (i);
}
