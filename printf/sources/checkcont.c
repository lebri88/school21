/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2020/01/02 19:45:37 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_string_and_check_null(t_info *in, char *str)
{
	int		ret;

	if (!str)
		return (0);
	if (in->content == char_null_)
		return (ft_print_char_null_with_width(in, str));
	else
	{
		ret = ft_strlen(str);
		write(1, str, ret);
		free(str);
		return (ret);
	}
}

char	*ft_apply_info_to_char(t_info *in, va_list ap)
{
	char	c;
	char	*temp;
	char	*ret;

	c = va_arg(ap, int);
	if (!(temp = ft_strnew(1)))
		in->error = 1;
	temp[0] = c;
	if (c == '\0')
		in->content = char_null_;
	if (in->width > 1 && c != '\0')
	{
		ret = ft_width_to_string(in, temp);
		free(temp);
		return (ret);
	}
	return (temp);
}

char	*ft_apply_info_to_string(t_info *in, va_list ap)
{
	char	*str;
	char	*ret;
	size_t	j;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		if (!(str = ft_string_null(str)))
			in->error = 1;
	}
	j = ft_strlen(str);
	if (in->precision >= 0 && (int)j > in->precision)
		str = ft_precision_to_string(in, str, in->precision);
	j = ft_strlen(str);
	if (in->width >= 0 && (int)j < in->width)
		str = ft_width_to_string(in, str);
	if (!(ret = ft_strdup(str)))
		in->error = 1;
	return (ret);
}
/*temporary here*/

char	*ft_apply_info_to_percent(t_info *in)
{
	char	*ret;
	char	*temp_space;
	char	fill;

	if (in->width > 1)
	{
		temp_space = ft_strnew(in->width - 1);
		fill = in->zero == 1 && in->minus != 1 ? '0' : ' ';
		temp_space = ft_memset(temp_space, fill, in->width - 1);
		if (in->minus == 1)
			ret = ft_strjoin("%", temp_space);
		else
			ret = ft_strjoin(temp_space, "%");
		ft_strdel(&temp_space);
		return (ret);
	}
	ret = ft_strsub("%", 0, 1);
	return (ret);
}

/*upper part to separate file*/

int		ft_print_content(t_info *in, va_list ap)
{
	char	*str;
	int		len;

	str = NULL;
	if (in->content == str_)
		str = ft_apply_info_to_string(in, ap);
	if (in->content == char_)
		str = ft_apply_info_to_char(in, ap);
	if (in->content == int_)
		str = ft_apply_info_to_int(in, ap);
	if (in->content == ptr_)
		str = ft_apply_info_to_ptr(in, ap);
	if (in->content == flt_ && in->size != L_)
		str = ft_apply_info_to_flt(in, ap);
	if (in->content == flt_ && in->size == L_)
		str = ft_apply_info_to_flt_long(in, ap);
	if (in->content == percent_)
		str = ft_apply_info_to_percent(in);
	len = ft_print_string_and_check_null(in, str);
	return (len);
}
