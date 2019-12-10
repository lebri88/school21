/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:49:38 by geliz             #+#    #+#             */
/*   Updated: 2019/12/08 19:37:24 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count(char c, int j)
{
	int		ret;

	ret = 1;
	if (c == '1')
	{
		while (j > 0)
		{
			ret = ret * 2;
			j--;
		}
		return (ret);
	}
	return (0);
}

unsigned long int	ft_binary_str_to_int(char *temp)
{
	int		i;
	int		j;
	unsigned long int ret;

	j = 0;
	ret = 0;
	i = (int)ft_strlen(temp) - 1;
	while (i > -1)
	{
		ret = ret + ft_count(temp[i], j);
		i--;
		j++;
	}
	return (ret);
}

char	*ft_binary_str_add_zero(char *temp, int len)
{
	char	*ret;
	int		j;

	ret = ft_strnew(len);
	j = (int)ft_strlen(temp);
	while (j > -1)
	{
		ret[len--] = temp[j--];
	}
	ft_strdel(&temp);
	return (ret);
}

char	*ft_apply_info_to_flt(t_info *in, va_list ap)
{
	t_float		d;
	t_db_bit	*db_bit;
	char		*temp;
	char		*temp2;

	d.d = va_arg(ap, double);

	if (!(db_bit = malloc(sizeof(t_db_bit))))
		return (NULL);
	temp = ft_unsigned_ll_itoa_base(d.t_bit.mantissa, 'b');
	//printf("\n%s\n", temp);
	temp2 = ft_unsigned_ll_itoa_base(d.t_bit.exponent, 'b');
	db_bit->exp = ft_binary_str_to_int(temp2) - 1023;
	temp = ft_binary_str_add_zero(temp, (int)db_bit->exp);
	db_bit->mant = ft_binary_str_to_int(temp);
	printf("exp = %lu, nmb = %lu\n", db_bit->exp, db_bit->mant);
//	printf("\n***exp = %lu**\n", db_bit->exp);
//	printf("\n%s\n", temp);
//	temp = ft_unsigned_ll_itoa_base(d.t_bit.sign, 'b');
//	printf("\n%s\n", temp);
	printf("\n%f", d.d);
	/*
	db_bit->mant = (ft_atoi(ft_unsigned_ll_itoa_base(d.t_bit.mantissa, 'b')));
	db_bit->exp = (ft_atoi(ft_unsigned_ll_itoa_base(d.t_bit.exponent, 'b')));
	db_bit->s = (ft_atoi(ft_unsigned_ll_itoa_base(d.t_bit.sign, 'b')));
	printf("\n bin mant = %lu\n bin exp = %lu\n bin s = %u", db_bit->mant, db_bit->exp, db_bit->s);*/
	return (NULL);
} 