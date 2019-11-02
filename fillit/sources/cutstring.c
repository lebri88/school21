/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:20:10 by geliz             #+#    #+#             */
/*   Updated: 2019/11/01 19:54:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
//		ft_bzero(arr[i], ft_strlen(arr[i]));
//		free(arr[i]);
		printf("%s\n", arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

char	**ft_copy_arr(char temp[4][4])
{
	int		strs;
	int		i;
	char	**res;

	strs = 0;
	i = 0;
	while (temp[strs])
		strs++;
	if (!(res = malloc(sizeof(char *) * (strs + 1))))
		return (NULL);
	res[strs] = NULL;
	while (i != strs)
	{
		if (!(res[i] = ft_strdup(temp[i])))
		{
			ft_free_arr(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

void	ft_clean_cols(char temp[4][4])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (temp[0][i] != '#' && temp[1][i] != '#' && temp[2][i] != '#'
				&& temp[3][i] != '#')
		{
			if (i == 0)
			{
				temp[0][0] = temp[0][1];
				temp[1][0] = temp[1][1];
				temp[2][0] = temp[2][1];
				temp[3][0] = temp[3][1];
/*				temp[0] = &temp[0][1];
				temp[1] = &temp[1][1];
				temp[2] = &temp[2][1];
				temp[3] = &temp[3][1];*/
			}
			else
			{
				temp[0][i] = '\0';
				temp[1][i] = '\0';
				temp[2][i] = '\0';
				temp[3][i] = '\0';
				i++;
			}
		}
		else
			i++;
	}
	i = 0;
}

void	ft_clean_strings(char temp[4][4])
{
	int		i;

	i = 0;
	while (temp[i])
	{
		if (ft_strchr(temp[i], '#') == NULL)
		{
			if (i == 0)
				temp = &temp[1];
			else
			{
//				temp[i][0] = NULL;
				i++;
			}
		}
		else
			i++;
	}
}

void	ft_create_arr(char temp[4][4], char *buf)
{
	int		i;
	int		col;
	int		str;
	int		test;

	i = 0;
	col = 0;
	str = 0;
	test = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
//			printf("buf = %s\n", buf);
			i++;
			temp[str][col] = '\0';
			while (test < col)
			{
				printf("%c", temp[str][col]);
				test++;
			}
			col = 0;
			str++;
		}
		temp[str][col] = buf[i];
		col++;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("%s\n", temp[i]);
		i++;
	}
}

char	**ft_cutstring(char *buf)
{
	char	temp[4][4];
	char	**split;
	int		i;

//	split = ft_strsplit(buf, '\n');
	ft_create_arr(temp, buf);
	ft_clean_cols(temp);
	ft_clean_strings(temp);
	split = ft_copy_arr(temp);
	ft_free_arr(split);
	i = 0;
	while (temp[i])
	{
//		printf("%s\n", temp[i]);
		i++;
	}
	return (split);
}
