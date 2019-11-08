/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:30 by geliz             #+#    #+#             */
/*   Updated: 2019/11/08 21:11:23 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map2(int s, char map[s][s]);
void	ft_print_map(int s, char temp[s][s]);

void	ft_paint_map(int s, char map[s][s], int x, int y, char **str)
{
	int		i;
	int		j;
	int		res;
	int		temp;

	i = 0;
	j = 0;
	res = 0;
	temp = y;
//	write(1, "@\n", 2);
	while (res != 4)
	{
		if (str[i][j] != '.' && str[i][j] != '\0')
		{
			map[x + i][y + j] = str[i][j];
			res++;
		}
		j++;
//		y++;
		if (str[i][j] == '\0')
		{
//			x++;
			i++;
//			y = temp;
			j = 0;
		}
	}
//	ft_print_map2(s, map);
}

void	ft_change_symbol(char **arr, char c)
{
	int 	i;
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

int		ft_check_op(int s, char map[s][s], int x, int y, char **str)
{
	int		i;
	int		j;
	int		res;
	int		temp;

	i = 0;
	j = 0;
	res = 0;
	temp = y;
//	printf("s = %i, x = %i, y = %i, str[i][j] = %c\n", s, x, y, str[i][j]);
//	write(1, "q\n", 2);
	while ((x + i) < s && str[i])
	{
		if (str[i][j] != '.' && str[i][j] != '\0' && (y + j) < s)
		{
//			write(1, "b", 1);
//			printf("i = %i, j = %i, x = %i, y = %i, s = %i\n", i, j, x, y, s);
			if (map[x + i][y + j] != '.')
				return (0);
			res++;
		}
		j++;
		if (str[i][j] == '\0')// || (y + j) == s)
		{
			j = 0;
			i++;
		}
/*		y++;
		if (y == s)
		{
			x++;
			i++;
			y = temp;
			j = 0;
		}*/
		if (res == 4)
			return (1);
	}
	return (0);
}

void	ft_print_map(int s, char map[s][s])
{
	int		i;
	int 	j;

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
	write(1, "\n", 1);
}

int		ft_opportunity(int s, char map[s][s], int x, int y, t_list *temp)
{
	char	**arr;
	char	c;
	int		ret;

//	write(1, "@\n", 2);
//	ft_print_map2(s, map);
	c = (char)temp->content_size;
//	printf("x = %i y = %i letter = %c\n", x, y, c);
	arr = temp->content;
	ret = ft_check_op(s, map, x, y, arr);
//	printf("ft_opport ret = %i\n", ret);
	if (ret == 1)
	{
		ft_change_symbol(arr, c);
		ft_paint_map(s, map, x, y, arr);
	}
//	ft_print_map(s, map);
	return (ret);
}
