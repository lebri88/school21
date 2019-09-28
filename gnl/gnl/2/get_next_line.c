/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:05:37 by geliz             #+#    #+#             */
/*   Updated: 2019/09/27 22:39:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 5

int		ft_checkcontent(t_list *temp, char **line, int res)
{
	char		*str;
	char		*tmp_str;
	size_t		i;
	
	i = 0;
	str = temp->content;
	if (temp->content == NULL || ft_strchr(str, 10) == NULL)
		return (1);
	else if (res < BUF_SIZE)
	{
		str = temp->content;
		line = &str;
		return (0);
	}
	else
	{
		str = temp->content;
		while (str[i] != '\n')
			i++;
		tmp_str = ft_strdup(&temp->content[i + 1]);
		str = ft_strnew(i);
		str = ft_strncpy(str, temp->content, i);
		free(temp->content);
		temp->content = tmp_str;
		line = &str;
		return (0);
	}
}

void	ft_fillstr(char *cont, char *buf, int res)
{
	char		*temp;
	char		*temp2;

	if (cont == NULL)
		cont = ft_strdup(buf);
	else if (res < BUF_SIZE)
	{
		temp = ft_strnew(res);
		temp = ft_strncpy(temp, buf, res);
		temp2 = ft_strjoin(cont, temp);
		free(cont);
		free(buf);
		free(temp);
		cont = temp2;
	}
	else
		cont = ft_strjoin(cont, buf);
}	

int		get_next_line(const int fd, char **line)
{
	t_list		*temp;
	t_list		*first;
	char		*buf;
	static int	x;
	int			res;

	buf = ft_strnew(BUF_SIZE);
	x = 0;
	res = BUF_SIZE;
	printf("so i'm in GNL\n");
	while (ft_checkcontent(temp, line, res) != 0)
	{
		printf("i'm in cicle checkcontent");
		res = read(fd, buf, BUF_SIZE);
		if (x == 0)
		{
			printf("let's see what we know about buf %s\n", buf);
			first = ft_lstnew(NULL, 0);
			first->content_size = fd;
			temp = first;
		}
		while (temp->next != NULL && temp->content_size != fd)
			temp = temp->next;
		if (temp->next == NULL && temp->content_size != fd)
		{
			temp->next = ft_lstnew(NULL, 0);
			temp = temp->next;
			temp->content_size = fd;
		}
		ft_fillstr(temp->content, buf, res);
		x++;
	}
	return (1);
}

int		main(int argn, char **argv)
{
	char		**line;
	int			fd;
	int			z;
	
	z = 1;
	if (argn < 2)
		return (1);
	printf("i'm here in MAIN before open\n");
	fd = open(argv[1], O_RDONLY);
	printf("i'm here after open oh, and fd = %i\n", fd);
	while (z == 1)
	{
		printf("i'm in z cicle\n");
		z = get_next_line(fd, line);
		printf("%s\n", *line);
	}
	return (0);
}
