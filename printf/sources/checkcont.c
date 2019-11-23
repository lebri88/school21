/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2019/11/23 20:11:33 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_info_to_char(t_info *in, va_list ap)
{
	char	c;
	char	*temp;
	char	*ret;
	
	c = va_arg(ap, int);
	if (!(temp = ft_strnew(1)))
		in->error = 1;
	temp[0] = c;
	if (in->width > 1)
	{
		ret = ft_width_to_string(in, temp);
		free(temp);
	}
	return (temp);
}

char    *ft_apply_info_to_string(t_info *in, va_list ap)
{
    char    *str;
	char	*ret;
    size_t  j;

    str = va_arg(ap, char *);
    if (str == NULL)
        {
            if (!(str = ft_string_null(str)))
                in->error = 1;
        }
    j = ft_strlen(str);
    if (in->precision >= 0 && j > in->precision)
        str = ft_precision_to_string(in, str, in->precision);
    j = ft_strlen(str);
    if (in->width >= 0 && ft_strlen(str) < in->width)
        str = ft_width_to_string(in, str);
	if (!(ret = ft_strdup(str)))
		in->error = 1;
    return (ret);    
}

int		ft_print_content(t_info *in, va_list ap)
{
	char	*str;
	int		len;

	if (in->content == str_)
		str = ft_apply_info_to_string(in, ap);
	if (in->content == char_)
		str = ft_apply_info_to_char(in, ap);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
