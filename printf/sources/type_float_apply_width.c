/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:14:12 by geliz             #+#    #+#             */
/*   Updated: 2019/12/22 16:24:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_without_minus_to_float(t_info *in, char *str)
{
	char	*ret;
	char	c;
	int		len;
	int		i;

	if (!(ret = ft_strnew(in->width)))
		return (NULL);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		ret[i] = str[i];
		i++;
	}
	len = (int)ft_strlen(str);
	c = in->zero == 1 ? '0' : ' ';
	ft_memset(&ret[i], c, (in->width - len));
	ft_strcat(&ret[in->width - len], &str[i]);
	ft_strdel(&str);
	return (ret);
}

char	*ft_width_with_minus_to_float(t_info *in, char *str)
{
	char	*ret;
	char	c;
	int		len;

	if (!(ret = ft_strnew(in->width)))
		return (NULL);
	len = (int)ft_strlen(str);
	c = ' ';
	ft_strcat(ret, str);
	ft_memset(&ret[len], c, (in->width - len));
	ft_strdel(&str);
	return (ret);
}

char	*ft_width_to_float(t_info *in, char *str)
{
	char	*ret;

	ret = str;
	if (in->minus == 1)
		ret = ft_width_with_minus_to_float(in, ret);
	else
		ret = ft_width_without_minus_to_float(in, ret);
	return (ret);
}
