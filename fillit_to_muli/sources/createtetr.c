/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createtetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:56:44 by geliz             #+#    #+#             */
/*   Updated: 2019/11/03 16:05:16 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_create_string(char temp[4][5], char *str)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (i < 4)
	{
		while (j < 5)
		{
			if (temp[i][j] != '\0')
			{
				str[z] = temp[i][j];
				z++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (str);
}

size_t	ft_count_symbols(char temp[4][5])
{
	int		i;
	int		j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (i < 4)
	{
		while (j < 5)
		{
			if (temp[i][j] != '\0')
				res++;
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}

char	**ft_create_tetr(char temp[4][5])
{
	size_t	len;
	char	*str;
	char	**split;

	len = ft_count_symbols(temp);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_create_string(temp, str);
	split = ft_strsplit(str, '\n');
	free(str);
	return (split);
}
