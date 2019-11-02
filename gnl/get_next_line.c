/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:08:16 by geliz             #+#    #+#             */
/*   Updated: 2019/10/19 14:33:22 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_giveline(t_list *temp, char *part)
{
	size_t			lenall;
	size_t			lenpart;
	char			*tmpstr;
	char			*ret;

	lenall = ft_strlen(temp->content);
	lenpart = ft_strlen(part);
	if (!(ret = ft_strsub(temp->content, 0, (lenall - lenpart))))
		return (NULL);
	if (!(tmpstr = ft_strsub(part, 1, (lenpart - 1))))
		return (NULL);
	free(temp->content);
	temp->content = tmpstr;
	tmpstr = NULL;
	part = NULL;
	return (ret);
}

static int		ft_fillstring(t_list *temp, char **line, char *part, int res)
{
	if (temp->content == NULL && res == 0)
		return (END);
	if (part != NULL)
	{
		if (!(*line = ft_giveline(temp, part)))
			return (ERROR);
		return (SUCCESS);
	}
	else
	{
		if (ft_strlen(temp->content) == 0)
		{
			free(temp->content);
			temp->content = NULL;
			return (END);
		}
		*line = temp->content;
		temp->content = NULL;
		return (SUCCESS);
	}
}

static int		ft_readplus(t_list *temp, char **line, char *buf)
{
	int				res;
	char			*ln;
	char			*findn;

	res = -1;
	ln = NULL;
	while ((findn = (ft_strchr(temp->content, '\n'))) == NULL && res != 0)
		if ((res = read(temp->content_size, buf, BUFF_SIZE)) > 0)
		{
			buf[res] = '\0';
			if (!(temp->content))
			{
				if (!(temp->content = ft_strdup(buf)))
					return (ERROR);
			}
			else
			{
				if (!(ln = ft_strjoin(temp->content, buf)))
					return (ERROR);
				free(temp->content);
				temp->content = ln;
				ln = NULL;
			}
		}
	return (ft_fillstring(temp, line, findn, res));
}

static t_list	*ft_findlist(t_list *first, int fd)
{
	t_list			*temp;
	t_list			*newlist;

	if ((int)first->content_size == fd)
		return (first);
	temp = first;
	while (temp->next)
	{
		temp = temp->next;
		if ((int)temp->content_size == fd)
			return (temp);
	}
	if (!(newlist = ft_lstnew(NULL, 0)))
		return (NULL);
	newlist->content_size = fd;
	temp->next = newlist;
	return (newlist);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*first;
	char			buf[BUFF_SIZE + 1];
	int				z;
	t_list			*temp;

	if (read(fd, NULL, 0) != 0)
		return (ERROR);
	if (!first)
	{
		if (!(first = ft_lstnew(NULL, 0)))
			return (ERROR);
		first->content_size = fd;
	}
	if (!(temp = ft_findlist(first, fd)))
		return (ERROR);
	z = ft_readplus(temp, line, buf);
	return (z);
}
