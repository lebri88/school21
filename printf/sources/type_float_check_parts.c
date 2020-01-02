/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_check_parts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:05:13 by geliz             #+#    #+#             */
/*   Updated: 2020/01/02 18:03:29 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char	*ft_check_divis(char *divis)
{
	size_t	j;
	char	*ret;

//	printf("\n***divis = %s***", divis);
	j = ft_strlen(divis);
	if (j < 6)
	{
		if (!(ret = ft_strnew(6)))
			return (NULL);
		j = 0;
		while (divis[j] != '\0')
		{
			ret[j] = divis[j];
			j++;
		}
		while (j < 6)
			ret[j++] = '0';
		ft_strdel(&divis);
		return (ret);
	}
	return (divis);
}*/

char	*ft_check_integ(char *integ)
{
	char	*ret;

	if (integ[0] == '\0')
	{
		if (!(ret = ft_strnew(1)))
			return (NULL);
		ret[0] = '0';
		ft_strdel(&integ);
		return (ret);
	}
	return (integ);
}

char	*ft_add_divis_to_integ(char *integ, char *divis, int sign, t_info *in)
{
	size_t	i;
	size_t	j;
	char	*ret;
	
	integ = ft_check_integ(integ);
//	divis = ft_check_divis(divis);
	if (sign == 0 && in->plus == 1)
		sign = 2;
	if (sign == 1)
		in->plus = 1;
	if (!(ret = ft_strnew(ft_strlen(integ) + ft_strlen(divis) + 1 + in->plus)))
		return (NULL);
	i = 0;
	j = 0;
	if (sign != 0)
		ret[j++] = sign == 1 ? '-' : '+';
	while (integ[i] != '\0')
		ret[j++] = integ[i++];
	ret[j++] = '.';
	i = 0;
	while (divis[i] != '\0')
		ret[j++] = divis[i++];
	ft_strdel(&integ);
	ft_strdel(&divis);
	return (ret);
}