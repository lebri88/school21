/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_print_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2020/01/03 19:01:40 by geliz            ###   ########.fr       */
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
		ft_strdel(&str);
		return (ret);
	}
}

int		ft_check_and_print_content(t_info *in, va_list ap)
{
	char	*str;
	int		len;

	str = NULL;
	if (in->size == L_ && in->content != flt_)
		in->size = ll_;
	if (in->content == percent_)
		str = ft_apply_info_to_percent(in);
	if (in->content == char_)
		str = ft_apply_info_to_char(in, ap);
	if (in->content == str_)
		str = ft_apply_info_to_string(in, ap);
	if (in->content == ptr_)
		str = ft_apply_info_to_ptr(in, ap);
	if (in->content == int_)
		str = ft_apply_info_to_int(in, ap);
	if (in->content == flt_ && in->size != L_)
		str = ft_apply_info_to_flt(in, ap);
	if (in->content == flt_ && in->size == L_)
		str = ft_apply_info_to_flt_long(in, ap);
	len = ft_print_string_and_check_null(in, str);
	return (len);
}
