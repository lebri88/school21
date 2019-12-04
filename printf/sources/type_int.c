/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:41:58 by geliz             #+#    #+#             */
/*   Updated: 2019/12/04 20:03:37 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_plus_to_int(char *ret)
{
	char		*temp;
	size_t		len;
	int			j;
	int			i;

	len = ft_strlen(ret);
	j = 0;
	i = 0;
	if (ret[0] != '-')
	{
		if (!(temp = ft_strnew(len + 1)))
			return (NULL);
		temp[i] = '+';
		i++;
		while (ret[j] != '\0')
		{
			temp[i] = ret[j];
			i++;
			j++;
		}
		ft_strdel(&ret);
		return (temp);
	}
	return (ret);
}

char	*ft_precision_to_int_with_minus(t_info *in, char *ret, int len)
{
	char		*temp;
	int			i;
	int			j;

	i = 1;
	j = 0;
	if (!(temp = ft_strnew(++in->precision)))
		return (NULL);
	temp[0] = '-';
	ret[0] = '0';
	while (in->precision > i)
	{
		while (in->precision > (len + i))
			temp[i++] = '0';
		temp[i++] = ret[j++];
	}
	ft_strdel(&ret);
	return (temp);
}

int		ft_is_nmb_zero(char *ret)
{
	int		z;

	
	if (ft_strlen(ret) > 1)
		return (0);
	z = ft_atoi(ret);
	if (z == 0)
	{
		ft_strdel(&ret);
		return (1);
	}
	return (0);
}

char	*ft_precision_to_int(t_info *in, char *ret, int len)
{
	char		*temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (ret[j] == '-')
	{
		if (!(temp = ft_precision_to_int_with_minus(in, ret, len)))
			return (NULL);
		return (temp);
	}
	if (!(temp = ft_strnew(in->precision)))
		return (NULL);
	while (in->precision > i)
	{
		while (in->precision > (len + i))
			temp[i++] = '0';
		temp[i++] = ret[j++];
	}
	ft_strdel(&ret);
	return (temp);
}

char    *ft_apply_info_to_int(t_info *in, va_list ap)
{
    char			*ret;
    int				len;

    if (!(ret = ft_convert_int_to_str(in, ap)))
		return (NULL);
	if (in->precision != -1)
		in->zero = 0;
	if (ret != NULL && in->octotorp == 1 && in->base != 'd')
		ret = ft_octotorp_to_int(in, ret);
	len = (int)ft_strlen(ret);
    if (in->precision > len)
		ret = ft_precision_to_int(in, ret, len);
	if (in->precision == 0 && in->base == 'd' && (ft_is_nmb_zero(ret) == 1))
		ret = ft_strnew(0);
	if (ret != NULL && in->plus == 1)
		ret = ft_plus_to_int(ret);
	if (ret != NULL && in->space == 1)
		ret = ft_space_to_int(in, ret);
	if (ret != NULL && in->width != -1)
	    ret = ft_width_to_int(in, ret);
	return (ret);
}
