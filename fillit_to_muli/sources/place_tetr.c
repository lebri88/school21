/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:30 by geliz             #+#    #+#             */
/*   Updated: 2019/11/09 17:35:33 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_paint_map(int s, char map[s][s], int crd[2], char **str)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (res != 4)
	{
		if (str[i][j] != '.' && str[i][j] != '\0')
		{
			map[crd[0] + i][crd[1] + j] = str[i][j];
			res++;
		}
		j++;
		if (str[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
}

int		ft_check_op(int s, char map[s][s], int crd[2], char **str)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while ((crd[0] + i) < s && str[i])
	{
		if (str[i][j] != '.' && str[i][j] != '\0' && (crd[1] + j) < s)
		{
			if (map[crd[0] + i][crd[1] + j] != '.')
				return (0);
			res++;
		}
		j++;
		if (str[i][j] == '\0')
		{
			j = 0;
			i++;
		}
		if (res == 4)
			return (1);
	}
	return (0);
}

int		ft_opportunity(int s, char map[s][s], int crd[2], t_list *temp)
{
	char	**arr;
	int		ret;

	arr = temp->content;
	ret = ft_check_op(s, map, crd, arr);
	if (ret == 1)
		ft_paint_map(s, map, crd, arr);
	return (ret);
}
