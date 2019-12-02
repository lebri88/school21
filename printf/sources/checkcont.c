/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2019/12/02 17:51:55 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_string_and_check_null(t_info *in, char *str)
{
	int		ret;

	if (!str)
		return (0);
	if (in->content == char_null_)
		return (ft_print_char_null_with_width(in, str));
	else
	{
		ret = ft_strlen(str);
		write(1, str, ret);
		free(str);
		return (ret);
	}
}

char	*ft_apply_info_to_char(t_info *in, va_list ap)
{
	char	c;
	char	*temp;
	char	*ret;
	
	c = va_arg(ap, int);
	if (!(temp = ft_strnew(1)))
		in->error = 1;
	temp[0] = c;
	if (c == '\0')
		in->content = char_null_;
	if (in->width > 1 && c != '\0')
	{
		ret = ft_width_to_string(in, temp);
		free(temp);
		return (ret);
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
    if (in->precision >= 0 && (int)j > in->precision)
        str = ft_precision_to_string(in, str, in->precision);
    j = ft_strlen(str);
    if (in->width >= 0 && (int)j < in->width)
        str = ft_width_to_string(in, str);
	if (!(ret = ft_strdup(str)))
		in->error = 1;
    return (ret);    
}

int		ft_print_content(t_info *in, va_list ap)
{
	char	*str;
	int		len;

	str = NULL;
	if (in->content == str_)
		str = ft_apply_info_to_string(in, ap);
	if (in->content == char_)
		str = ft_apply_info_to_char(in, ap);
	if (in->content == int_)
		str = ft_apply_info_to_int(in, ap);
	len = ft_print_string_and_check_null(in, str);
	return (len);
}
