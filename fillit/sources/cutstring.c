/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:20:10 by geliz             #+#    #+#             */
/*   Updated: 2019/11/03 17:49:46 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_strings(char temp[4][5])
{
	int 	i;

	i = 0;
	while (i < 4)
	{
		if (temp[i][0] != '#' && temp[i][1] != '#' && temp[i][2] != '#'
			   && temp[i][3] != '#')
			ft_bzero(temp[i], 5);
		i++;
	}
}

void	ft_clean_cols(char temp[4][5])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (temp[0][i] != '#' && temp[1][i] != '#' && temp[2][i] != '#'
				&& temp[3][i] != '#')
		{
			temp[0][i] = '\0';
			temp[1][i] = '\0';
			temp[2][i] = '\0';
			temp[3][i] = '\0';
		}
		i++;
	}
}
void	ft_create_arr(char temp[4][5], char *buf)
{
	int		i;
	int		col;
	int		str;

	i = 0;
	col = 0;
	str = 0;
	while (buf[i] != '\0')
	{
		temp[str][col] = buf[i];
		col++;
		if (buf[i] == '\n')
		{
			str++;
			col = 0;
		}
		i++;
	}
}

char	**ft_cutstring(char *buf)
{
	char	temp[4][5];
	char	**split;

	ft_create_arr(temp, buf);
	ft_clean_cols(temp);
	ft_clean_strings(temp);
	split = ft_create_tetr(temp);
	return (split);
}
