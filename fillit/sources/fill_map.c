/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:38:31 by geliz             #+#    #+#             */
/*   Updated: 2019/11/04 20:24:48 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_opportunity(int s, char map[s][s], int x, int y, t_list *temp);
void	ft_print_map2(int s, char[s][s]);
int		ft_create_map(int side, t_list *first, int x, int y);

void	ft_print_map(int s, char temp[s][s])
{
	while (*temp)
	{
		printf("%s\n", *temp);
		temp++;
	}
}

int		ft_place_tetr(int s, char map[s][s], int x, int y, t_list *temp)
{
	if (ft_opportunity(s, map, x, y , temp) != 0)
	{
//		ft_print_map2(s, map);
		return (1);
	}
	return (0);
}

int		ft_place_tetr_hub(int s, char map[s][s], t_list *first, int x, int y)
{
	int		ret;
//	char	**tempmap;
	
	ret = 0;
	while (ret != 1 && x < s)
	{
		if ((ft_place_tetr(s, map, x, y, first) == 1) && x < s)
		{
			ft_print_map2(s, map);
			if (((ft_place_tetr_hub(s, map, first->next, x, y)) == 1) && x < s)
			{
//				ft_print_map2(s, map);
				ret = 1;
			}
		}
//		else
		y++;
		if (y == s)
		{
			y = 0;
			x++;
		}
	}
	if (ret != 1)
	{
		y = y + 1;
		if (y == s)
		{
			y = 0;
			x = x + 1;
		}
		ft_create_map(s, first, x, y);
	}
	return (ret);
}
/*
char	**ft_create_map(int side)
{
	int		i;
	char	**map;

	if (!(map = malloc(sizeof(char *) * (side + 1))))
		return (NULL);
	i = 0;
	while (i < side)
	{
		if (!(map[i] = ft_strnew(side)))
		{
			ft_free_array(map);
			return (0);
		}
		map[i] = ft_memset(map[i], '.', side);
		printf("%s\n", *map);//
		i++;
	}
	return (map);
}
*/
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
	while (res * res <= i)
		res++;
	return (4);//UBRAT'!!!!
}

int		ft_create_map(int side, t_list *first, int x, int y)
{
	char	map[side][side];
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	while (i < side)
	{
		while (j < side)
		{
			map[i][j] = '.';
//			write(1, &map[i][j], 1);
			j++;
		}
//		write(1, "\n", 1);
		j = 0;
		i++;
	}
//	ft_print_map2(side, map);
	ret = ft_place_tetr_hub(side, map, first, x, y);
	printf("create map ret = %i\n", ret);
	return (ret);
}

int		ft_fill_map(t_list *first)
{
	int		side;
	int		ret;
//	char	**map;

	ret = 0;
	side = ft_count_side_size(first);
	while (ret != 1)
	{
//		if (!(map = ft_create_map(side)))
//			return (0);
		ret = ft_create_map(side, first, 0, 0);
//		map = ft_place_tetr_hub(side, first, 0, 0);
//		if (map)
//			ret = 1;
		printf("ft_fill_map ret = %i\n", ret);
		side++;
	}
	return (1);
}
