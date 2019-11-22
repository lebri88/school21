/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:28:32 by geliz             #+#    #+#             */
/*   Updated: 2019/11/22 16:40:25 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill_content_size(t_list *first)
{
	int		i;

	i = 0;
	while (first)
	{
		first->content_size = ('A' + i);
		if (first->content_size > 'Z')
			return (0);
		first = first->next;
		i++;
	}
	return (1);
}

void	ft_free_array(char **arr)
{
	int		i;
	int		z;

	i = 0;
	z = 0;
	while (arr[i] != NULL)
		i++;
	while (z < i)
	{
		free(arr[z]);
		arr[z] = NULL;
		z++;
	}
	free(arr);
	arr = NULL;
}

void	ft_clean_list(t_list *first)
{
	t_list	*temp;

	if (first)
	{
		temp = first;
		while (temp != NULL)
		{
			temp = first->next;
			first->content_size = 0;
			if (first->content)
				ft_free_array(first->content);
			first->next = NULL;
			free(first);
			first = temp;
		}
	}
}

int		ft_fill_list(char **tetr, t_list *first)
{
	t_list	*temp;
	t_list	*new;

	if (first->content == NULL)
	{
		first->content = tetr;
		return (1);
	}
	temp = first;
	while (temp->next)
		temp = temp->next;
	if (!(new = ft_lstnew(NULL, 0)))
		return (0);
	new->content = tetr;
	temp->next = new;
	return (1);
}
