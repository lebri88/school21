/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_apply_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:22:22 by geliz             #+#    #+#             */
/*   Updated: 2019/12/22 19:46:54 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_round_up_integ_part(char *nbr, int len, int prec)
{
	char	*ret;
	char	i;
	int		pos;
	int		ost;
	int		n;
	
	i = len + prec;
	pos = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
		pos = 1;
	ost = 1;
	while (--len >= pos && ost == 1)
	{
		n = (nbr[len] - '0') + ost;
		nbr[len] = n % 10 + '0';
		ost = n / 10 > 0 ? 1 : 0;
	}
	if (!(ret = ft_strnew(i + ost)))
		return (NULL);
	len = 0;
	if (pos == 1)
		ret[len] = nbr[len];
	len = len + pos;
	if (ost == 1)
		ret[len + ost] = '1';
	while (len <= (i + ost))
	{
		ret[len + ost] = nbr[len];
		len++;
	}
	ft_strdel(&nbr);
	return (ret);
}

char	*ft_precision_less_cut_str(char *nbr, int len, int prec)
{
	char	*ret;
	int		i;
	int		n;
	int		ost;

//	ret = ft_strnew(len - (af_dot - prec));
//	i = -1;
//	while (nbr[++i] != '.')
//		ret[i] = nbr[i];
//	ret[i] = '.';
	i = prec;
	ost = nbr[len + prec + 1] > '4' ? 1 : 0;
	//while (i > 0)
//		if (ost == 0)
//			ret[i + prec] = nbr[i + prec];
//		else
	while (ost == 1 && i > 0)
	{
		n = (nbr[len + i] - '0') + ost;
		nbr[len + i] = n % 10 + '0';
		ost = n / 10 > 0 ? 1 : 0;
		i--;
	}
	if (ost == 1)
		ret = ft_precision_round_up_integ_part(nbr, len, prec);
	else
	{
		if (!(ret = ft_strnew(len + prec)))
			return (NULL);
		i = -1;
		while (++i < len + prec)
			ret[i] = nbr[i];
	}
	return (ret);
}

char	*ft_precision_more_add_zero(char *nbr, int len, int af_dot, int prec)
{
	char	*ret;
	int		dif;
	int		j;

	dif = prec - af_dot;
	j = 0;
	if (!(ret = ft_strnew(len + prec)))
		return (NULL);
	while (nbr[j] != '\0')
	{
		ret[j] = nbr[j];
		j++;
	}
	while (dif-- >= 0)
		ret[j++] = '0';
	ft_strdel(&nbr);
	return (ret);
}

int		ft_precision_zero_round_up(char *nbr, int i, int pos)
{
	int		ost;
	int		n;
	
	ost = 0;
	if (nbr[i + 1] > '4')
	{
		ost = 1;
		while (--i >= pos)
		{
			n = (nbr[i] - '0') + ost;
			nbr[i] = n % 10 + '0';
			ost = n / 10 > 0 ? 1 : 0;
		}
	}
	return (ost);
}

char	*ft_precision_float_zero(char *nbr, int i)
{
	char	*ret;
	int		ost;
	int		pos;

	pos = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
		pos = 1;
	ost = ft_precision_zero_round_up(nbr, i, pos);
	if (!(ret = ft_strnew(i + ost)))
		return (NULL);
	i = 0;
	if (pos == 1)
	{
		ret[i] = nbr[i];
		i++;
	}
	if (ost == 1)
		ret[i++] = '1';
	while (nbr[i - ost] != '.')
	{
		ret[i] = nbr[i - ost];
		i++;
	}
	return (ret);
}

char	*ft_precision_to_float(int prec, char *nbr)
{
	int		len;
	int		af_dot;
	char	*ret;
	int		i;

	len = 0;
	af_dot = 0;
	while (nbr[len] != '.')
		len++;
	if (prec == 0)
		ret = ft_precision_float_zero(nbr, len);
	i = len;
	while (nbr[i++] != '\0')
		af_dot++;
	if (prec == -1)
		prec = 6;
	if (prec > 0 && prec == af_dot)
		return(nbr);
	if (prec > af_dot)
		ret = ft_precision_more_add_zero(nbr, len, af_dot, prec);
	if (prec > 0 && prec < af_dot)
		ret = ft_precision_less_cut_str(nbr, len, prec);
	return (ret);

}

char	*ft_keys_width_prec_to_float(t_info *in, char *nbr)
{
	char	*ret;

	ret = nbr;
	ret = ft_precision_to_float(in->precision, nbr);
	if (ret != NULL && in->width > (int)ft_strlen(ret))
		ret = ft_width_to_float(in, ret);
//	printf("\n%s\n", ret);
	if (ret)
		return (ret);
	else
		return (nbr);
}
