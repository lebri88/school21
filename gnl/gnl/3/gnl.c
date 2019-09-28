/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:57:54 by geliz             #+#    #+#             */
/*   Updated: 2019/09/28 18:42:56 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 5

int		ft_strchk(char *ln, char **line)
{
	char	*newl;
	char	*temp;
	size_t	i;
	size_t	j;
	
	printf("i'm in check\n");
	i = 0;
	j = ft_strlen(ln);
	if ((newl = ft_strchr(ln, '\n')) != NULL)
	{
		while (newl[i] != '\0')
			i++;
		temp = ft_strsub(newl, 0, i);
		newl = ft_strsub(ln, 0, (ft_strlen(ln) - i));
		*line = newl;
		ln = temp;
		return (0);
	}
	else
		return (1);
}

int		get_next_line(int fd, char **line)
{
	char	*buf;
	int		res;
	char	*ln;
	int		x;
	char	*tmp;

	x = 1;
	buf = ft_strnew(BUF_SIZE);
	while ((res = read(fd, buf, BUF_SIZE)) > 0 && res == BUF_SIZE)
	{
		if (x == 1)
		{
			ln = ft_strnew(BUF_SIZE);
			ln = ft_strncpy(ln, buf, BUF_SIZE);
			printf("first read buf = %s, ln = %s\n", buf, ln);
			x = 0;
		}
		else
		{
			ln = ft_strjoin(ln, buf);
			printf("another GNL cicle buf = %s, ln = %s\n", buf, ln);
		}
		if (ft_strchk(ln, line) < 1)
			return (0);
	}
	if (res != 0 && res < BUF_SIZE)
	{
		tmp = ft_strnew(res);
		tmp = ft_strncpy(tmp, buf, res);
		ln = ft_strjoin(ln, tmp);
		*line = ln;
		return (0);
	}
	if (res == 0)
	{
		*line = ln;
		return (0);
	}
	return (0);
}

int		main(int argn, char **argv)
{
	if (argn < 2)
		return (0);
	char	**str;
	int		fd;
	int		z;
	
	fd = open(argv[1], O_RDONLY);
	z = 1;
	while (z > 0)
	{
		printf("while in main\n");
		z = get_next_line(fd, str);
		printf("IN MAIN = %s\n", *str);
	}
	return (0);
}
