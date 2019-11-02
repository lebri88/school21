/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:47:11 by geliz             #+#    #+#             */
/*   Updated: 2019/11/01 16:29:05 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validate_lines(char *buf)
{
	int		ret;

	ret = ft_check_newlines(buf);
	if (ret != 0)
		ret = ft_check_symbols(buf);
	if (ret != 0)
		ret = ft_check_figure(buf);
	return (ret);
}

int		ft_check_newlines(char *buf)
{
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n'
			|| buf[19] != '\n')
		return (0);
	return (1);
}

int		ft_check_symbols(char *buf)
{
	int		filled;
	int		empty;
	int		i;

	filled = 0;
	empty = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '.')
			empty++;
		if (buf[i] == '#')
			filled++;
		i++;
	}
	if (empty != 12 || filled != 4)
		return (0);
	return (1);
}

int		ft_check_figure(char *buf)
{
	int     i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '#')
		{
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				j++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				j++;
			if ((i + 1) <= 19 && buf[i + 1] == '#')
				j++;
			if ((i + 5) <= 19 && buf[i + 5] == '#')
				j++;
		}
		i++;
	}
	if (j == 6 || j == 8)
		return (1);
	return (0);
}
