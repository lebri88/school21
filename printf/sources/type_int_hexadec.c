/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int_hexadec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:55:30 by geliz             #+#    #+#             */
/*   Updated: 2019/12/07 20:12:01 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char	*ft_precision_to_int_minus_hexadec(t_info *in, char *ret, int len)
{
	char	*temp;
	int		i;
	int		j;


}
*/
char	*ft_precision_to_int_base_hexadec(t_info *in, char *ret, int len)
{
	char	*temp;
	int		i;
	int		j;
	
//	if ((in->precision + 2) <= len)
//		return (ret);
	if (len == 1 && ret[0] == '0')
	{
		in->octotorp = 0;
		return (ft_precision_to_int(in, ret));
	}
	in->precision = in->precision + 2;
	len = len - 2;
	i = 2;
	j = 2;
/*	if (in->minus == 1)
		return (ft_precision_to_int_minus_hexadec(in, ret, len));*/
	if (!(temp = ft_strnew(in->precision)))
		return (NULL);
	temp[0] = ret[0];
	temp[1] = ret[1];
	while (in->precision > i)
	{
		while (in->precision > (len + i))
			temp[i++] = '0';
		temp[i++] = ret[j++];
	}
	ft_strdel(&ret);
	return (temp);
}

char	*ft_width_with_zero_to_hexadec_int(t_info *in, char *temp, char *ret, int len)
{
	int		i;
	int		j;

	if (len == 1 && ret[0] == '0')
	{
		in->octotorp = 0;
		return (ft_width_with_zero_to_int(in, ret));
	}
	i = 2;
	j = 2;
	temp[0] = ret[0];
	temp[1] = ret[1];
	len = len - 2;
	while (in->width > j)
	{
		while (in->width > (len + j))
			temp[j++] = '0';
		temp[j++] = ret[i++];
	}
	ft_strdel(&ret);
	return (temp);
}
