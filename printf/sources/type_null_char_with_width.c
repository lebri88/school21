/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_null_char_with_width.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:14:02 by geliz             #+#    #+#             */
/*   Updated: 2019/12/02 17:43:16 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_char_null_width_plus(t_info *in)
{
    int     ret;

    ret = in->width;
    while (in->width != 1)
    {
        write(1, " ", 1);
        in->width--;
    }
    write (1, "\0", 1);
    return (ret);
}

int     ft_char_null_width_minus(t_info *in)
{
    int     ret;
    
    ret = in->width;
    write(1, "\0", 1);
    in->width--;
    while (in->width != 0)
    {
        write(1, " ", 1);
        in->width--;
    }
    return (ret);
}

int     ft_print_char_null_with_width(t_info *in, char *str)
{
    int     ret;

    ret = 0;
    ft_strdel(&str);
    if (in->width <= 1)
    {
        write(1, "\0", 1);
        return (1);
    }
    if (in->minus == 1)
        ret = ft_char_null_width_minus(in);
    else
        ret = ft_char_null_width_plus(in);
    return (ret);
}