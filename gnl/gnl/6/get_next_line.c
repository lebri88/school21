/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:10:56 by geliz             #+#    #+#             */
/*   Updated: 2019/10/06 18:12:14 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUF_SIZE 200
#include <stdio.h>

int		ft_check_content(t_list *first, int fd, int res, char **line)
{
	char			*str;
	char			*nw;
	
	while (first->next != NULL && (int)first->content_size != fd)
	{
//		printf("NO 1\n");
		first = first->next;
	}
	str = first->content;
//	printf("-str = %s\n", str);
	if (first->content == NULL)
		return (0);
	if (res < BUF_SIZE && (nw = ft_strchr(first->content, '\n')) == NULL)
	{
//		printf("NO3 %s\n", str);
		*line = str;
		return (2);
	}
	if ((nw = ft_strchr(first->content, '\n')) != NULL)
	{
//		printf("********************************************************NO 2\n");
		if (!(nw = ft_strsub(str, (ft_strlen(str) - ft_strlen(nw) + 1), (ft_strlen(nw) - 1))))
			return (-1);
//		printf("-------------%s, res = %i\n", nw, res);
		if (!(str = ft_strsub(str, 0, (ft_strlen(str) - ft_strlen(nw) - 1))))
			return (-1);
//		printf("-----------%s\n", str);
		*line = str;
//		printf("** line = %s\n", **line);
		first->content = nw;
		return (1);
	}
/*	if (res < BUF_SIZE && (nw = ft_strchr(first->content, '\n')) == NULL)
	{
		printf("NO3 %s\n", str);
		*line = str;
		return (2);
	}*/
//	printf("***check done***\n");
//	peredelat' esli res < buf_size
	return (0);
}

int		ft_fill_string(t_list *temp, char *buf, int res)
{
	char			*ln;

//	printf("if fill string\n");
	ln = temp->content;
//	printf("0000temp->content =  %s**//buf = %s\n", temp->content, buf);
	if (!temp->content)
		if (!(temp->content = ft_strnew(BUF_SIZE)))
			return (-1);
//	printf("ln = %s\n", ln);
	if (res <= BUF_SIZE)
		if (!(temp->content = ft_strjoin(temp->content, buf)))
			return (-1);
//	printf("ln after strjoin = %s\n", temp->content);
//	printf("tempcont = %s\n", temp->content);
/*	if (res < BUF_SIZE)
	{
		printf("////////%s\n", temp->content);
		if (!(temp->content = ft_strsub(temp->content, ft_strlen(temp->content),
						(ft_strlen(temp->content) + res))))
			return (-1);
		printf("************%s\n", temp->content);
	}*/
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
	int				j;

	if (fd < 1)
		return (-1);
	if (!(buf = ft_strnew(BUF_SIZE)))
		return (-1);
	if (!first)
		if (!(first = ft_lstnew(NULL, 0)))
			return (-1);
	res = BUF_SIZE;
	while ((j = ft_check_content(first, fd, res, line)) == 0)
	{
		if ((res = read(fd, buf, BUF_SIZE)) > 0)
		{	
//			printf("res = %i\n", res);
			if (first->content_size == 0)
			{
				first->content_size = fd;
			}
			if (!(temp = ft_find_list(first, fd)))
				return (-1);
			if (ft_fill_string(temp, buf, res) == -1)
				return (-1);
		}
//		printf("res2 = %i\n", res);
	}
	if (j== -1)
		return (-1);
	if (j == 2)
		return (0);
	return (1);
}
