/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:12:42 by geliz             #+#    #+#             */
/*   Updated: 2019/11/24 17:52:06 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_width_without_minus(t_info *in, char *str, char *ret)
{
    int     i;
    size_t  len;
    char    c;

    i = 0;
    len = ft_strlen(str);
    c = ' ';
    if (in->space == 0 && in->zero == 1)
        c = '0';
    while (i < (in->width - (int)len))
    {
        ret[i] = c;
        i++;
  //      if (i == in->width - (int)len && str[0] == '\0')
   //         ret[i] = '\0';
    }
    len = 0;
    while (str[len] != '\0')
    {
        ret[i] = str[len];
        len++;
        i++;
    }
    return (ret);
}

char    *ft_width_with_minus(t_info *in, char *str, char *ret)
{
    int     i;
    char    c;

    i = 0;
    c = ' ';
    while (str[i] != '\0')
    {
        ret[i] = str[i];
        i++;
    }
 /*   if (str[0] == '\0' && str[1] == '\0')
    {
        ret[i] = '\0';
        i++;
    }*/
    while (i < in->width)
    {
        ret[i] = c;
        i++;
    }
    return (ret);
}

char    *ft_width_to_string(t_info *in, char *str)
{
    char    *ret;
    int     len;

    len = (int)ft_strlen(str);
    if (len > in->width)
        ret = ft_strnew(len);
    else
        ret = ft_strnew(in->width);
    if (!ret)
    {
        in->error = 1;
        return (NULL);
    }
    if (in->minus == 1)
        ret = ft_width_with_minus(in, str, ret);
    else
        ret = ft_width_without_minus(in, str, ret);
    return (ret);
}

char    *ft_precision_to_string(t_info *in, char *str, int prec)
{
    char    *ret;

    if (prec == 0)
    {
        if (!(ret = ft_strnew(0)))
            in->error = 1;
        return (ret);
    }
    if (!(ret = ft_strsub(str, 0, prec)))
        in->error = 1;
    str = NULL;
    return (ret);
}

char	*ft_string_null(char *str)
{
	if (!(str = ft_strnew(6)))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	return (str);
}
