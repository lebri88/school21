/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:32:30 by geliz             #+#    #+#             */
/*   Updated: 2019/09/22 20:52:25 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

typedef struct		s_list
{
	char			*str;
	size_t			filed;
	struct s_list	*next;
}					t_list;
/* may be we shouldn't create "oldstring" and just putstr from "str" somehow*/

void	ft_list_remove(t_list *first, t_list *temp)
{
	t_list	*t;
	t_list	*pret;

	pret = first;
	t = first->next;
	while (t->filed != temp->filed)
	{
		pret = t;
		t = t->next;
	}
	pret->next = t->next;
	ft_strdel(t->str);
	t->filed = 0;
	t->next == NULL;
	free (t);
}

char	*ft_printandfree(char *str, size_t i)
{
	size_t	j;
	char	*newstr;
	char	*oldstr;

	if (!(oldstr = ft_strnew(i)))
		return (NULL);
	oldstr = ft_strncpy(oldstr, str, i);
	if (!(newstr = ft_strsub(str, i, (ft_strlen(str) - i))))
		return (NULL);
	ft_putstr(oldstr);
	ft_strdel(&str);
	ft_strdel(&oldstr);
	return (newstring);
}

int		ft_fill_str(t_list *temp, size_t fd, char *buf)
{
	size_t	i;
	char	*tstr;
	
	if (temp->str == NULL)
	{
		temp->filed = fd;
		if (!(temp->str = ft_strnew(BUF_SIZE)))
			return (0);
		temp->str = ft_strcpy(temp->str, buf);
	}
	else
		if (!(tstr = ft_strjoin(temp->str, buf)))
			return (0);
	i = 0;
	while (temp->str[i] != '\n' || temp->str[i] != EOF || temp->str != '\0')
		i++;
	if (temp->str[i] == '\n')
		if (!(temp->str = ft_printandfree(temp->str, i)))
			return (0);
	if (temp->str[i] == EOF)
	{
		ft_putstr(str);
		return (-1);
	}
/*	peredat' v structure list1 dlja udalenija listov iz ljubogo mesta?..	*/
	return (1);
}

t_list	*ft_create_list(t_list *prev)
{
	t_list			*newlist;
	static size_t	i;

	i = 1;
	newlist = malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->str = NULL;
	if (newlist == NULL)
		return (NULL);
	newlist->filed = 0;
	if (i != 1)
		prev->next = newlist;
	newlist->next = NULL;
	i++;
	return (newlist);
}

int		get_next_line(const int fd, char **line)
{
	t_list	*first;
	t_list	*temp;
	char	*buf;
	int		err;

	buf = malloc(sizeof(char) * BUF_SIZE);
	first = ft_create_list(temp);
	if (first == NULL)
		return (NULL);
	temp = first;
	temp_first = first;
	while(read(fd, buf, BUF_SIZE) != 0)
	{
		while (temp->next != NULL && fd != temp->filed)
			temp = temp->next;
		if (temp->next == NULL)
			temp = ft_create_list(temp);
		err = ft_fill_str(temp, fd, buf);
		if (err == NULL)
			return NULL;
		if (err == -1)
			ft_list_remove(first, temp);
		temp = first;
	}
}
/*
int		main(int argn, char **argv)
{
	open-read-gnl;
}*/
