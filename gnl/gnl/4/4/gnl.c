/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:57:54 by geliz             #+#    #+#             */
/*   Updated: 2019/09/28 21:26:30 by geliz            ###   ########.fr       */
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

int		get_next_line(int fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	static char	*ln;
	int			res;
	char		*nw;
	size_t		i;

	if (fd < 0)
		return (0);
	if (!ln)
		ln = ft_strnew(BUF_SIZE);
	buf[BUF_SIZE] = '\0';
	i = 0;
	while ((res = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (res == BUF_SIZE)
			ln = ft_strjoin(ln, buf);
		if (res < BUF_SIZE)
		{
			ln = ft_strsub(ln, ft_strlen(ln), (ft_strlen(ln) + res));
			*line = ln;
			return (0);
		}
		if ((nw = ft_strchr(ln, '\n')) != NULL)
		{
//			printf("**here**\n");
			i = ft_strlen(nw);
//			while (nw[i] != '\0')
//				i++;
//			printf("buf = %s | cut size = %zu\n", buf, i);
			nw = ft_strsub(ln, (ft_strlen(ln) - i + 1), (i - 1));
//			printf("nw = %s\n", nw);
			ln = ft_strsub(ln, 0, (ft_strlen(ln) - i));
//			printf("ln = %s\n", ln);
			*line = ln;
//			printf("*line = %s\n", *line);
			ln = nw;
//			printf("ln cut = %s\n", ln);
			return (1);
		}
	}
	return (0);
}

int		main(int argn, char **argv)
{
	if (argn < 2)
		return (0);
	char	*str;
	int		fd;
	int		z;
	
	fd = open(argv[1], O_RDONLY);
	z = 1;
	while (get_next_line(fd, &str))
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
