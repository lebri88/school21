/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:10:56 by geliz             #+#    #+#             */
/*   Updated: 2019/09/29 17:26:47 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUF_SIZE 10
#include <stdio.h>

int		ft_check_content(t_list *first, int fd, int res, char **line)
{
	char			*str;
	char			*nw;
	
	printf("in check cont\n");
	while (first != NULL && (int)first->content_size != fd)
	{
		printf("looking for fd\n");
		first = first->next;
	}
	printf("checkin cont2\n");
	if (first == NULL)
	{
		return (0);
	}
	str = first->content;
	printf("str = %s\n", str);
	if ((nw = ft_strchr(first->content, '\n')) != NULL)
	{
		printf("SHOULD NOT BE HERE\n");
		if (!(nw = ft_strsub(str, (ft_strlen(str) - ft_strlen(nw) + 1), (ft_strlen(nw) - 1))))
			return (-1);
		if (!(str = ft_strsub(str, 0, (ft_strlen(str) - ft_strlen(nw)))))
			return (-1);
		*line = str;
		str = nw;
		return (1);
	}
	if (res < BUF_SIZE)
		*line = str;
	return (0);
}

int		ft_fill_string(t_list *temp, char *buf, int res)
{
	char			*ln;

	printf("if fill string\n");
	ln = temp->content;
	if (!temp->content)
		if (!(temp->content = ft_strnew(BUF_SIZE)))
			return (-1);
	printf("ln = %s\n", ln);
	if (res == BUF_SIZE)
		if (!(temp->content = ft_strjoin(temp->content, buf)))
			return (-1);
	printf("ln after strjoin = %s\n", ln);
	printf("tempcont = %s\n", temp->content);
	if (res < BUF_SIZE)
		if (!(temp->content = ft_strsub(temp->content, ft_strlen(temp->content),
						(ft_strlen(temp->content) + res))))
			return (-1);
	return (0);
}

t_list	*ft_find_list(t_list *first, int fd)
{
	t_list			*tmp;
	t_list			*newlist;

	if ((int)first->content_size == fd)
		return (first);
	tmp = first;
	while (tmp->next)
	{
		tmp = tmp->next;
		if ((int)tmp->content_size == fd)
			return (tmp);
	}
	if (!(newlist = ft_lstnew(NULL, 0)))
		return (NULL);
	newlist->content_size = fd;
	tmp->next = newlist;
	return (newlist);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*first;
	t_list			*temp;
	char			*buf;
	int 			res;

	if (fd < 0) 
		return (-1);
//	printf("fd > 0\n");
	if (!(buf = ft_strnew(BUF_SIZE)))
		return (-1);
//	printf ("buf created\n");
	if (!first)
		first = ft_lstnew(NULL, 0);
//	printf("first created\n");
	res = BUF_SIZE;
	while (ft_check_content(first, fd, res, line) == 0)
	{
//		printf("here\n");
		if ((res = read(fd, buf, BUF_SIZE)) > 0)
		{	
			printf("buf = %s \n", buf);
			if (first->content_size == 0)
				first->content_size = fd;
			if (!(temp = ft_find_list(first, fd)))
				return (-1);
			if (ft_fill_string(temp, buf, res) == -1)
				return (-1);
		}
	}
	return (1);
}
