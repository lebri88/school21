/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:12:42 by geliz             #+#    #+#             */
/*   Updated: 2019/11/23 19:53:33 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_width_without_minus(t_info *in, char *str, char *ret)
{
    size_t  i;
    size_t  len;
    char    c;

    i = 0;
    len = ft_strlen(str);
    if (in->zero == 1)
        c = '0';
    else
        c = ' ';
    while (i < (in->width - len))
    {
        ret[i] = c;
        i++;
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
    size_t  i;
    char    c;

    i = 0;
    if (in->zero == 1)
        c = '0';
    else
        c = ' ';
    while (str[i] != '\0')
    {
        ret[i] = str[i];
        i++;
    }
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

    if (!(ret = ft_strnew(in->width)))
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
