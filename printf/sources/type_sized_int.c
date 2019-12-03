/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sized_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:37:10 by geliz             #+#    #+#             */
/*   Updated: 2019/12/03 20:24:01 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_apply_info_to_int_hh_char(t_info *in, va_list ap)
{
	char		*ret;
	int			nmb;
	int			len;
	char		c;

	c = va_arg(ap, int);
	nmb = (int)c;
	if (!(ret = ft_itoa(nmb)))
        return (NULL);
    len = (int)ft_strlen(ret);
	if (in->precision != -1)
		in->zero = 0;
    if (in->precision > len)
		ret = ft_precision_to_int(in, ret, len);
	if (in->precision == 0 && nmb == 0)
		ret = ft_strnew(0);
	if (ret != NULL && in->plus == 1)
		ret = ft_plus_to_int(ret);
	if (ret != NULL && in->space == 1)
		ret = ft_space_to_int(in, ret);
	if (ret != NULL && in->width != -1)
	    ret = ft_width_to_int(in, ret);
	return (ret);
}
char	*ft_apply_info_to_short_int(t_info *in, va_list ap)
{
	char			*ret;
	int				nmb;
	int				len;
	short int		nmb2;

	nmb = va_arg(ap, int);
	nmb2 = (short)nmb;
	if (!(ret = ft_itoa(nmb2)))
        return (NULL);
    len = (int)ft_strlen(ret);
	if (in->precision != -1)
		in->zero = 0;
    if (in->precision > len)
		ret = ft_precision_to_int(in, ret, len);
	if (in->precision == 0 && nmb == 0)
		ret = ft_strnew(0);
	if (ret != NULL && in->plus == 1)
		ret = ft_plus_to_int(ret);
	if (ret != NULL && in->space == 1)
		ret = ft_space_to_int(in, ret);
	if (ret != NULL && in->width != -1)
	    ret = ft_width_to_int(in, ret);
	return (ret);
}

char	*ft_apply_info_to_long_long_int(t_info *in, va_list ap)
{
	char			*ret;
	long long int	nmb;
	int				len;

	nmb = va_arg(ap, long long int);
	if (!(ret = ft_long_long_itoa(nmb)))
        return (NULL);
    len = (int)ft_strlen(ret);
	if (in->precision != -1)
		in->zero = 0;
    if (in->precision > len)
		ret = ft_precision_to_int(in, ret, len);
	if (in->precision == 0 && nmb == 0)
		ret = ft_strnew(0);
	if (ret != NULL && in->plus == 1)
		ret = ft_plus_to_int(ret);
	if (ret != NULL && in->space == 1)
		ret = ft_space_to_int(in, ret);
	if (ret != NULL && in->width != -1)
	    ret = ft_width_to_int(in, ret);
	return (ret);
}

char	*ft_apply_info_to_long_int(t_info *in, va_list ap)
{
	char		*ret;
	long int	nmb;
	int			len;

	nmb = va_arg(ap, long int);
	if (!(ret = ft_long_long_itoa(nmb)))
        return (NULL);
    len = (int)ft_strlen(ret);
	if (in->precision != -1)
		in->zero = 0;
    if (in->precision > len)
		ret = ft_precision_to_int(in, ret, len);
	if (in->precision == 0 && nmb == 0)
		ret = ft_strnew(0);
	if (ret != NULL && in->plus == 1)
		ret = ft_plus_to_int(ret);
	if (ret != NULL && in->space == 1)
		ret = ft_space_to_int(in, ret);
	if (ret != NULL && in->width != -1)
	    ret = ft_width_to_int(in, ret);
	return (ret);
}

char	*ft_apply_info_to_sized_int(t_info *in, va_list ap)
{
	char			*ret;

	if (in->unsign == 0)
	{
		if (in->size == l_)
			ret = ft_apply_info_to_long_int(in, ap);
		if (in->size == ll_)
			ret = ft_apply_info_to_long_long_int(in, ap);
		if (in->size == h_)
			ret = ft_apply_info_to_short_int(in, ap);
		if (in->size == hh_)
			ret = ft_apply_info_to_int_hh_char(in, ap);
	}
	else
	{
		if (in->size == l_)
			ret = ft_apply_info_to_unsigned_long_int(in, ap);
		if (in->size == ll_)
			ret = ft_apply_info_to_unsigned_long_long_int(in, ap);
		if (in->size == h_)
			ret = ft_apply_info_to_unsigned_short_int(in, ap);
		if (in->size == hh_)
			ret = ft_apply_info_to_int_hh_unsigned_char(in, ap);
	}
	return (ret);
}