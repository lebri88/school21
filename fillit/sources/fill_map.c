/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:38:31 by geliz             #+#    #+#             */
/*   Updated: 2019/11/09 17:35:50 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_create_map(int side, t_list *first)
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
	ret = ft_first_tetr_iter(side, map, first);
	return (ret);
}

void	ft_change_symbol(char **arr, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == '#')
				arr[i][j] = c;
			j++;
		}
		j = 0;
		i++;
	}
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

int		ft_fill_map(t_list *first)
{
	int		side;
	int		ret;
	t_list	*temp;

	ret = 0;
	side = ft_count_side_size(first);
	temp = first;
	while (temp)
	{
		ft_change_symbol((char **)temp->content, (char)temp->content_size);
		temp = temp->next;
	}
	while (ret != 1)
	{
		ret = ft_create_map(side, first);
		if (ret == 0)
			side++;
	}
	return (1);
}
