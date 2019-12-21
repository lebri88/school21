/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_neg_powers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:45:33 by geliz             #+#    #+#             */
/*   Updated: 2019/12/21 17:19:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_summ_divis_strings(char res[310], char temp[310])
{
		int		i;
		int		nbr;
		int		ost;

		i = 0;
		ost = 0;
		while (res[i] != 0 || temp[i] != 0)
		{
			if (res[i] == 0)
				res[i] = '0';
			if (temp[i] == 0)
				temp[i] = '0';
			i++;
		}
		i--;
		while (i > -1)
		{
				nbr = (temp[i] - '0') + (res[i] - '0') + ost;
				ost = nbr / 10 > 0 ? 1 : 0;
				res[i] = nbr % 10 + '0';
				i--;
		}
}

void	ft_reverse_array(char arr[310])
{
	int		i;
	int		j;
	char	temp[310];

	i = 0;
	j = 0;
	while (i < 309)
		temp[i++] = '\0';
	i = 0;
	while (arr[i] != 0)
		i++;
	while (i > 0)
		temp[j++] = arr[--i];
	i = 0;
	while (arr[i] != 0)
	{
		arr[i] = temp[i];
		i++;
	}
}

void	ft_neg_pow_cycle(char temp[310])
{
		int		i;
		int		ost;
		int		tmp;
		int		zero;

		i = 0;
		ost = 0;
		zero = 0;
		while (temp[i] != 0)
		{
				tmp = (temp[i] - '0') * 5 + ost;
				ost = tmp / 10 > 0 ? (tmp / 10) : 0;
				temp[i] = tmp % 10 + '0';
				i++;
		}
		if (temp[i] == 0 && ost > 0)
		{
				temp[i] = ost + '0';
				ost = 0;
		}
		//if (temp[i] == '1')
		//		zero++;
		//return (zero);
}

void	ft_negative_power(char temp[310], int pow)
{

		int		i;
		int		zero_ct;

		i = 0;
		while (temp[i] != 0)
				temp[i++] = 0;
		temp[0] = '1';
		i = 0;
		zero_ct = -1;
		pow = pow * (-1);
		while (pow > 0)
		{
				while (temp[i] != 0)
					i++;
				if (temp[i - 1] == '1')
					zero_ct++;
//				zero_ct = zero_ct + ft_neg_pow_cycle(temp);
				ft_neg_pow_cycle(temp);
				pow--;
		}
		while (temp[i] != 0)
				i++;
		while (zero_ct-- > 0)
				temp[i++] = '0';
//		temp[i] = '.';
//		temp[i + 1] = '0';
}

char	*ft_negative_power_to_mant(char *mant, int j, int pow)
{
		char	*ret;
		char	res[310];
		char	temp[310];
//		int		del_me;

//		del_me = 0;
		ft_fill_array_with_zero(res, temp);
		while (mant[j] != '\0')
		{
				if (mant[j] == '1')
				{
//						printf("\npow = %i", pow);
						ft_negative_power(temp, pow);
						ft_reverse_array(temp);
//						printf("\n");
//						while (temp[del_me] != 0)
//							printf("%c", temp[del_me++]);
//						del_me = 0;
						ft_summ_divis_strings(res, temp);
				}
				j++;
				pow--;
		}
		ft_reverse_array(res);
		ret = ft_array_to_string(res);
//		printf("\nnegat part = %s", ret);
		return (ret);
}
