/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:30:04 by geliz             #+#    #+#             */
/*   Updated: 2019/12/04 20:11:39 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_octotorp_to_X_big(char *str, size_t len)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_strnew(len + 2)))
		return (NULL);
	ret[0] = '0';
	ret[1] = 'X';
	while (str[i] != '\0')
	{
		ret[i + 2] = str[i];
		i++;
	}
	return (ret);
}

char	*ft_octotorp_to_x_small(char *str, size_t len)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_strnew(len + 2)))
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	while (str[i] != '\0')
	{
		ret[i + 2] = str[i];
		i++;
	}
	return (ret);
}

char	*ft_octotorp_to_o(t_info *in, char *str, size_t len)
{
	char	*ret;
	int		i;

	if (in->precision == 0 && len == 1 && str[0] == '0')
	{
		if (!(ret = ft_strnew(0)))
			return (NULL);
		return (ret);
	}
	if (len == 1 && str[0] == '0')
		return (str);
	i = 0;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	ret[0] = '0';
	while (str[i] != '\0')
	{
		ret[i + 1] = str[i];
		i++;
	}
	return (ret);
}

char	*ft_octotorp_to_int(t_info *in, char *ret)
{
	char	*str;
	size_t	len;

	len = ft_strlen(ret);
	if (in->base == 'o')
		str = ft_octotorp_to_o(in, ret, len);
	if (in->base == 'x')
		str = ft_octotorp_to_x_small(ret, len);
	if (in->base == 'X')
		str = ft_octotorp_to_X_big(ret, len);
	return (str);
}