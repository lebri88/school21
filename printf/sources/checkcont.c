/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2019/11/17 15:47:45 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrn(char *str, int j)
{
	int		i;

	i = 0;
	while (i < j && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_string_flag(t_info *in, int i, int j, char *str)
{
	if (in->minus == 1)
	{
		ft_putstrn(str, j);
		while (in->width > j)
		{
			write(1, " ", 1);
			j++;
		}
	}
	if (in->minus == 0)
	{
		while ((in->width - j) > i)
		{
			write(1, " ", 1);
			i++;
		}
		ft_putstrn(str, j);
		j = j + i;
	}
	return (j);
}

int		ft_print_string(t_info *in, va_list ap)
{
	char	*str;
	int		j;
	int		i;

	str = va_arg(ap, char *);
	j = ft_strlen(str);
	if (j > in->precision && in->precision >= 0)
		j = in->precision;
	i = 0;
	j = ft_string_flag(in, i, j, str);
	return (j);
}
