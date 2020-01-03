/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:53:59 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 15:08:28 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_null_width_plus(t_info *in)
{
	int		ret;
	char	*temp;

	ret = in->width;
	if (in->width > 1)
	{
		if (!(temp = ft_strnew(in->width - 1)))
			return (-1);
		temp = ft_memset(temp, ' ', in->width - 1);
		write(1, temp, in->width - 1);
	}
	write(1, "\0", 1);
	return (ret);
}

int		ft_char_null_width_minus(t_info *in)
{
	int		ret;
	char	*temp;

	ret = in->width;
	write(1, "\0", 1);
	in->width--;
	if (in->width > 0)
	{
		if (!(temp = ft_strnew(in->width)))
			return (-1);
		temp = ft_memset(temp, ' ', in->width);
		write(1, temp, in->width);
	}
	return (ret);
}

int		ft_print_char_null_with_width(t_info *in, char *str)
{
	int		ret;

	ret = 0;
	ft_strdel(&str);
	if (in->width <= 1)
	{
		write(1, "\0", 1);
		return (1);
	}
	if (in->minus == 1)
		ret = ft_char_null_width_minus(in);
	else
		ret = ft_char_null_width_plus(in);
	return (ret);
}

char	*ft_apply_info_to_char(t_info *in, va_list ap)
{
	char	c;
	char	*temp;
	char	*ret;

	c = va_arg(ap, int);
	if (!(temp = ft_strnew(1)))
		return (NULL);
	temp[0] = c;
	if (c == '\0')
		in->content = char_null_;
	if (in->width > 1 && c != '\0')
	{
		ret = ft_width_to_string(in, temp);
		ft_strdel(&temp);
		return (ret);
	}
	return (temp);
}
