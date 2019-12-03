/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:06:56 by geliz             #+#    #+#             */
/*   Updated: 2019/12/03 20:20:05 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_info_to_int_hh_unsigned_char(t_info *in, va_list ap)
{
	char			*ret;
	int				nmb;
	int				len;
	unsigned char	c;

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

char	*ft_apply_info_to_unsigned_short_int(t_info *in, va_list ap)
{
	char				*ret;
	int					nmb;
	int					len;
	unsigned short int	nmb2;

	nmb = va_arg(ap, int);
	nmb2 = (unsigned short)nmb;
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

char	*ft_apply_info_to_unsigned_long_long_int(t_info *in, va_list ap)
{
	char					*ret;
	unsigned long long int	nmb;
	int						len;

	nmb = va_arg(ap, unsigned long long int);
	if (!(ret = ft_unsigned_long_long_itoa(nmb)))
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

char	*ft_apply_info_to_unsigned_long_int(t_info *in, va_list ap)
{
	char			*ret;
	long long int	nmb;
	int				len;

	nmb = va_arg(ap, unsigned long int);
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

char	*ft_apply_info_to_unsigned_int(t_info *in, va_list ap)
{
	char			*ret;
	unsigned int	nmb;
	int				len;

	nmb = va_arg(ap, unsigned int);
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