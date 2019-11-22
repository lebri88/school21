/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:37:30 by geliz             #+#    #+#             */
/*   Updated: 2019/11/09 17:47:48 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		ft_print_map(int s, char map[s][s])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s)
	{
		while (j < s)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (1);
}

int		ft_place_tetr_hub(int s, char map[s][s], t_list *first, int tmp[2])
{
	int		ret;
	char	tempmap[s][s];
	int		crd[2];

	if (first == NULL)
		return (ft_print_map(s, map));
	crd[0] = tmp[0];
	crd[1] = tmp[1];
	if (first->content_size != 'A')
		ft_memset(crd, 0, (sizeof(int) * 2));
	ret = 0;
	ft_map_copy(s, map, tempmap);
	while (ret != 1 && crd[0] < s)
	{
		if (ft_opportunity(s, tempmap, crd, first) == 1)
			ret = ft_place_tetr_hub(s, tempmap, first->next, crd);
		ft_map_copy(s, map, tempmap);
		if (crd[1]++ == s)
		{
			crd[1] = 0;
			crd[0]++;
		}
	}
	return (ret);
}

int		ft_first_tetr_iter(int s, char map[s][s], t_list *first)
{
	int		crd[2];
	int		ret;

	crd[0] = 0;
	crd[1] = 0;
	ret = 0;
	while (ret != 1 && crd[0] < s)
	{
		ret = ft_place_tetr_hub(s, map, first, crd);
		crd[1]++;
		if (crd[1] == s)
		{
			crd[1] = 0;
			crd[0]++;
		}
	}
	return (ret);
}
