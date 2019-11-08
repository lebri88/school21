/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:38:31 by geliz             #+#    #+#             */
/*   Updated: 2019/11/08 21:31:45 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_opportunity(int s, char map[s][s], int x, int y, t_list *temp);
void	ft_print_map(int s, char[s][s]);
int		ft_create_map(int side, t_list *first, int x, int y);

void	ft_map_copy(int s, char map[s][s], char temp[s][s])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s)
	{
		while (j < s)
		{
			temp[i][j] = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_place_tetr_hub(int s, char map[s][s], t_list *first,
		int x, int y)
{
	int		ret;
	char	tempmap[s][s];

	ret = 0;
	x = 0;
	y = 0;
	ft_map_copy(s, map, tempmap);
	if (first == NULL)
	{
		ft_print_map(s, tempmap);
		return (1);
	}
	while (ret != 1 && x < s)
	{
		if (ft_opportunity(s, tempmap, x, y, first) == 1)
			ret = ft_place_tetr_hub(s, tempmap, first->next, x, y);
		ft_map_copy(s, map, tempmap);
		y++;
		if (y == s)
		{
			y = 0;
			x++;
		}
	}
	return (ret);
}

int		ft_count_side_size(t_list *first)
{
	int		i;
	int		res;

	i = 0;
	res = 2;
	while (first)
	{
		first = first->next;
		i++;
	}
	i = i * 4;
	while (i > (res * res))
		res++;
	return (res);
}

int		ft_create_map(int side, t_list *first, int x, int y)
{
	char	map[side][side];
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	while (i < side)
	{
		while (j < side)
		{
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	ret = ft_place_tetr_hub(side, map, first, x, y);
	return (ret);
}

int		ft_fill_map(t_list *first)
{
	int		side;
	int		ret;

	ret = 0;
	side = ft_count_side_size(first);
	while (ret != 1)
	{
		ret = ft_create_map(side, first, 0, 0);
		if (ret == 0)
			side++;
	}
	return (1);
}
