/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:10:56 by geliz             #+#    #+#             */
/*   Updated: 2019/10/09 18:49:49 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_content(t_list *first, int fd, int res, char **line)
{
	char			*str;
	char			*nw;

	while (first->next != NULL && (int)first->content_size != fd)
		first = first->next;
	if (first->content && (nw = ft_strchr(first->content, '\n')) != NULL)
	{
		if (!(nw = ft_strsub(first->content, (ft_strlen(first->content) -
							ft_strlen(nw) + 1), (ft_strlen(nw) - 1))))
			return (-1);
		if (!(str = ft_strsub(first->content, 0, (ft_strlen(first->content)
							- ft_strlen(nw) - 1))))
			return (-1);
		*line = str;
		free(first->content);
		first->content = nw;
		return (0);
	}
	else if (first->content && res < BUFF_SIZE)
	{
		*line = first->content;
		return (0);
	}
	return (1);
}

int		ft_fill_string(t_list *temp, char *buf, int res)
{
	char			*ln;

	if (!temp->content)
		if (!(temp->content = ft_strnew(BUFF_SIZE)))
			return (-1);
	if (res <= BUFF_SIZE)
	{
		if (!(ln = ft_strjoin(temp->content, buf)))
			return (-1);
		free(temp->content);
		temp->content = ln;
	}
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

int		ft_readplus(t_list *first, int fd, char **line, char *buf)
{
	t_list			*temp;
	int				res;
	int				err;

	res = BUFF_SIZE;
	while ((err = ft_check_content(first, fd, res, line)) == 1)
	{
		if ((res = read(fd, buf, BUFF_SIZE)) > 0)
		{
			if (first->content_size == 0)
				first->content_size = fd;
			if (!(temp = ft_find_list(first, fd)))
				return (-1);
			if (ft_fill_string(temp, buf, res) == -1)
				return (-1);
		}
	}
	if (res == 0)
		return (2);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*first;
	char			*buf;
	int				z;

	if (!(buf = ft_strnew(BUFF_SIZE)) || read(fd, NULL, 0) != 0)
		return (-1);
	if (!first)
		if (!(first = ft_lstnew(NULL, 0)))
		{
			free(buf);
			return (-1);
		}
	z = ft_readplus(first, fd, line, buf);
	free(buf);
	if (z == -1)
		return (-1);
	if (z == 2)
		return (0);
	return (1);
}
