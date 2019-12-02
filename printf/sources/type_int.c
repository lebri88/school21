/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:41:58 by geliz             #+#    #+#             */
/*   Updated: 2019/12/02 20:31:33 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*char	*ft_width_to_int(t_info *in, char *ret)
{
	char		*temp;
	size_t		len;

	len = ft_strlen(ret);
	if (in->width > len)
	{
		if (in->minus == 1)
	
	}
}*/

char	*ft_space_to_int(t_info *in, char *ret)
{
	char		*temp;
	size_t		len;
	int			j;

	j = 0;
	if (in->plus == 1)
		return (ret);
	len = ft_strlen(ret);
	if (!(temp = ft_strnew(len + 1)))
		return (NULL);
	*temp = ' ';
	temp++;
	while (ret[j] != '\0')
	{
		*temp = ret[j];
		temp++;
		j++;
	}
	ft_strdel(&ret);
	return (temp);
}

char	*ft_plus_to_int(char *ret)
{
	char		*temp;
	size_t		len;
	int			j;

	len = ft_strlen(ret);
	j = 0;
	if (ret[0] != '-')
	{
		if (!(temp = ft_strnew(len + 1)))
			return (NULL);
		*temp = '+';
		temp++;
		while (ret[j] != '\0')
		{
			*temp = ret[j];
			temp++;
			j++;
		}
		ft_strdel(&ret);
		return (temp);
	}
	return (ret);
}

char	*ft_precision_to_int(t_info *in, char *ret, int len)
{
	char		*temp;
	int			i;
	int			j;

	if (!(temp = ft_strnew(in->precision)))
		return (NULL);
	i = 0;
	j = 0;
	while (in->precision > (len + i))
	{
		temp[i] = '0';
		i++;
	}
	while (in->precision > i)
	{
		temp[i] = ret[j];
		i++;
		j++;
	}
	ft_strdel(&ret);
	return (temp);
}

char    *ft_apply_info_to_int(t_info *in, va_list ap)
{
    char		*ret;
    long int	nmb;
    int			len;

    nmb = va_arg(ap, int);
    if (!(ret = ft_itoa(nmb)))
        return (NULL);
    len = (int)ft_strlen(ret);
    if (in->precision > len)
		ret = ft_precision_to_int(in, ret, len);
	if (ret != NULL && in->plus == 1)
		ret = ft_plus_to_int(ret);
	if (ret != NULL && in->space == 1)
		ret = ft_space_to_int(in, ret);
	if (ret != NULL && in->width != -1)
	    ret = ft_width_to_string(in, ret);
	return (ret);
}
