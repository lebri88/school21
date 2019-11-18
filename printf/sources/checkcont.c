/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkcont.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:29 by geliz             #+#    #+#             */
/*   Updated: 2019/11/17 17:42:05 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// rename checkcont.c -> string.c
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
	char	c;

	c = ' ';
	if (in->minus == 1)
	{
		ft_putstrn(str, j);
		while (in->width > j)
		{
			write(1, &c, 1);
			j++;
		}
	}
	if (in->minus == 0)
	{
		if (in->zero == 1)
			c = '0';
		while ((in->width - j) > i)
		{
			write(1, &c, 1);
			i++;
		}
		ft_putstrn(str, j);
		j = j + i;
	}
	return (j);
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

int		ft_print_string(t_info *in, va_list ap)
{
	char	*str;
	int		j;
	int		i;

	str = va_arg(ap, char *);
	if (str == NULL)
		{
			if (!(str = ft_string_null(str)))
				return (-1);
		}
	j = ft_strlen(str);
	if (j > in->precision && in->precision >= 0)
		j = in->precision;
	i = 0;
	j = ft_string_flag(in, i, j, str);
	return (j);
}
