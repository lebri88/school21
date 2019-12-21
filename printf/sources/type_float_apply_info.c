/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:22:22 by geliz             #+#    #+#             */
/*   Updated: 2019/12/21 18:23:43 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_less_cut_str(char *nbr, int len, int af_dot, int prec)
{
	char	*ret;
	int		dif;
	int		n;
	int		ost;

	dif = af_dot - prec;
	ret = ft_strnew(len - dif);
	dif = 0;
	ost = 0;
	while (nbr[dif] != '.')
	{
		ret[dif] = nbr[dif];
		dif++;
	}
	ret[dif] = '.';
	ost = nbr[dif + prec + 1] > '4' ? 1 : 0;
	/*
	{
		ost = 1;
		n = (nbr[dif + prec] - '0') + 1;
		nbr[dif + prec] = n % 10 + '0' + ost;
		ost = n / 10 > 0 ? 1 : 0;
	}*/
	while (prec > 0)
	{
		if (ost == 0)
			ret[dif + prec] = nbr[dif + prec];
		else
		{
			n = (nbr[dif + prec] - '0') + ost;
			ret[dif + prec] = n % 10 + '0';
			ost = n / 10 > 0 ? 1 : 0;
		}
		prec--;
	}
	return (ret);
}

char	*ft_precision_more_add_zero(char *nbr, int len, int af_dot, int prec)
{
	char	*ret;
	int		dif;

	dif = prec - af_dot;
	if (!(ret = ft_strnew(len + dif)))
		return (NULL);
	dif = 0;
	while (nbr[dif] != '\0')
	{
		ret[dif] = nbr[dif];
		dif++;
	}
	while (ret[dif] != '\0')
		ret[dif++] = '0';
	ft_strdel(&nbr);
	return (ret);
}

char	*ft_precision_to_float(int prec, char *nbr)
{
	int		i;
	int		af_dot;
	char	*ret;

	i = 0;
	af_dot = 0;
	while (nbr[i] != '.')
		i++;
	if (prec == 0)
	{
		ret = ft_strsub(nbr, 0, i);
		ft_strdel(&nbr);
		return (ret);
	}
	while (nbr[i++] != '\0')
		af_dot++;
	if (prec > af_dot)
		ret = ft_precision_more_add_zero(nbr, i, af_dot, prec);
	if (prec < af_dot)
		ret = ft_precision_less_cut_str(nbr, i, af_dot, prec);
	return (ret);

}

char	*ft_keys_width_prec_to_float(t_info *in, char *nbr)
{
	char	*ret;

	ret = NULL;
	if (in->precision > -1)
		ret = ft_precision_to_float(in->precision, nbr);
//	printf("\n%s\n", ret);
	if (ret)
		return (ret);
	else
		return (nbr);
}