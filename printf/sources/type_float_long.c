/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:45:31 by geliz             #+#    #+#             */
/*   Updated: 2020/01/02 18:48:47 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_nan_and_inf_long(t_info *in, t_lfloat d)
{
	char	*ret;
	char	*temp;

	ret = NULL;
	if (d.ld != d.ld)
	{
		if (!(temp = ft_strsub("nan", 0, 3)))
			return (NULL);
		if (in->width > 3)
		{
			ret = ft_width_to_inf_or_nan(in, temp);
			ft_strdel(&temp);
			return (ret);
		}
		return (temp);
	}
	if (d.t_lbit.exponent == 32767)
	{
		return (ret = ft_keys_to_inf(in, ret, d.t_lbit.sign));
	}
	return (NULL);
}

char	*ft_apply_info_to_flt_long(t_info *in, va_list ap)
{
	t_lfloat	d;
	int			exp;
	char		*nbr;
	char		*temp;

	d.ld = va_arg(ap, long double);
	nbr = ft_check_nan_and_inf_long(in, d);
	if (nbr)
		return (nbr);
//	printf("\n%i\n", d.t_bit.sign);
	nbr = ft_unsigned_ll_itoa_base(d.t_lbit.mantissa, 'b');
//	printf("old mant = %s, len = %zu", nbr, ft_strlen(nbr));
	temp = ft_unsigned_ll_itoa_base(d.t_lbit.exponent, 'b');
//	printf("\n\n, mant bit = %s\nexp bin = %s, exp long = %lu, mant long = %lu", nbr, temp, d.t_lbit.exponent, d.t_lbit.mantissa);
	//if (d.t_bit.mantissa == 0 && d.t_bit.exponent == )
	exp = ft_binary_str_to_int(temp) - 16383;
//	nbr = ft_add_zero_and_hidden_to_mant(nbr, exp);
//	printf("\nmant = %s, len = %zu, exp = %i\n", nbr, ft_strlen(nbr), exp);
	nbr = ft_apply_exp_to_mantissa(nbr, exp, d.t_lbit.sign, in);
//	printf("\nnbr = %s\n", nbr);

	nbr = ft_keys_width_prec_to_float(in, nbr);
	return (nbr);
}