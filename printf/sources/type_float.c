/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:49:38 by geliz             #+#    #+#             */
/*   Updated: 2019/12/27 20:10:32 by geliz            ###   ########.fr       */
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
	ret = ft_strnew(53);
	ret[0] = exp == -1023 ? '0' : '1';
	i = ft_strlen(temp);
	if (i < 52)
	{
		i = 52 - i;
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
//	printf("\n%i\n", d.t_bit.sign);
	nbr = ft_unsigned_ll_itoa_base(d.t_bit.mantissa, 'b');
//	printf("old mant = %s, len = %zu", nbr, ft_strlen(nbr));
	temp = ft_unsigned_ll_itoa_base(d.t_bit.exponent, 'b');
//	printf("\nexp bin = %s", temp);
	exp = ft_binary_str_to_int(temp) - 1023;
	nbr = ft_add_zero_and_hidden_to_mant(nbr, exp);
//	printf("\nmant = %s, len = %zu, exp = %i\n", nbr, ft_strlen(nbr), exp);
	nbr = ft_apply_exp_to_mantissa(nbr, exp, d.t_bit.sign, in->plus);
//	printf("\nnbr = %s\n", nbr);

	nbr = ft_keys_width_prec_to_float(in, nbr);
	return (nbr);
} 