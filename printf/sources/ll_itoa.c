/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:27:56 by geliz             #+#    #+#             */
/*   Updated: 2019/12/04 17:10:29 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(long long int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_convert(char *str, long long int n, size_t i)
{
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char			*ft_ll_itoa(long long int n)
{
	char	*str;
	int		i;

	i = ft_intlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str = ft_convert(str, n, (i - 1));
	return (str);
}
