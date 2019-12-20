/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:49:38 by geliz             #+#    #+#             */
/*   Updated: 2019/12/20 22:17:13 by geliz            ###   ########.fr       */
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

int		ft_binary_str_to_int(char *temp)
{
	int		i;
	int		j;
	int		ret;

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

char	*ft_add_zero_and_hidden_to_mant(char *temp, int exp)
{
	char	*ret;
	size_t	i;
	size_t	j;

	j = 1;
	ret = ft_strnew(52);
	ret[0] = exp == -1023 ? '0' : '1';
	i = ft_strlen(temp);
	if (i < 51)
	{
		i = 51 - i;
		while(i-- > 0)
			ret[j++] = '0';
	}
	i = 0;
	while (temp[i] != '\0')
		ret[j++] = temp[i++];
	ft_strdel(&temp);
	return (ret);
}

char	*ft_apply_info_to_flt(t_info *in, va_list ap)
{
	t_float		d;
	int			exp;
	char		*nbr;
	char		*temp;

	d.d = va_arg(ap, double);
	nbr = ft_unsigned_ll_itoa_base(d.t_bit.mantissa, 'b');
	temp = ft_unsigned_ll_itoa_base(d.t_bit.exponent, 'b');
	exp = ft_binary_str_to_int(temp) - 1023;
	nbr = ft_add_zero_and_hidden_to_mant(nbr, exp);
	nbr = ft_apply_exp_to_mantissa(nbr, exp);
	printf("\nnbr = %s\n", nbr);
	return (NULL);
} 