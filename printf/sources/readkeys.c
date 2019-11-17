/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readkeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:08:33 by geliz             #+#    #+#             */
/*   Updated: 2019/11/17 15:25:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_content(const char *c, int i, t_info *in)
{
	if (c[i] == 's')
	{
		in->content = 1;
		i++;
		return (i);
	}
	return (i);
}

int		ft_size(const char *c, int i, t_info *in)
{
	if (in->size == 0)
	{
		if (c[i] == 'h' && c[i + 1] == 'h')
			in->size = 1;
		if (c[i] == 'h' && in->size == 0)
			in->size = 2;
		if (c[i] == 'l' && c[i + 1] == 'l')
			in->size = 3;
		if (c[i] == 'l' && in->size == 0)
			in->size = 4;
	}
	if (in->size == 1 || in->size == 3)
		return (i + 2);
	if (in->size == 2 || in->size == 4)
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