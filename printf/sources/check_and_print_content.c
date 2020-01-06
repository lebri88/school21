/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_print_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2020/01/06 19:16:12 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_string_and_check_null(t_info *in, char *str)
{
	int		ret;

	if (!str)
		return (0);
	if (in->content == CHAR_NULL_)
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
	if (in->size == LBIG_ && in->content != FLT_)
		in->size = LL_;
	if (in->content == PERCENT_)
		str = ft_apply_info_to_percent(in);
	if (in->content == CHAR_)
		str = ft_apply_info_to_char(in, ap);
	if (in->content == STR_)
		str = ft_apply_info_to_string(in, ap);
	if (in->content == PTR_)
		str = ft_apply_info_to_ptr(in, ap);
	if (in->content == INT_)
		str = ft_apply_info_to_int(in, ap);
	if (in->content == FLT_ && in->size != LBIG_)
		str = ft_apply_info_to_flt(in, ap);
	if (in->content == FLT_ && in->size == LBIG_)
		str = ft_apply_info_to_flt_long(in, ap);
	if (in->content == BINAR_)
		str = ft_apply_info_to_binary(in, ap);
	len = ft_print_string_and_check_null(in, str);
	return (len);
}
