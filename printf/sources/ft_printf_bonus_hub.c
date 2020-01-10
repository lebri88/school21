/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_hub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:58:08 by geliz             #+#    #+#             */
/*   Updated: 2020/01/10 18:19:05 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprintf(int fd, const char *c, ...)
{
	t_info		*info;
	va_list		ap;
	char		*str;

	if (fd == -1)
		return (0);
	info = NULL;
	if (!(info = ft_create_info(info, 0)))
		return (-1);
	va_start(ap, c);
	str = ft_printf_cycle(c, info, ap);
	if (!str)
		return (0);
	write(fd, str, info->position);
	ft_strdel(&str);
	va_end(ap);
	free(info);
	return (info->position);
}

t_color	*ft_create_color_list(t_color *list)
{
	if (!(list = malloc(sizeof(t_color) * 1)))
		return (NULL);
	list->black = ft_strsub("{black}", 0, 7);
	list->red = ft_strsub("{red}", 0, 5);
	list->green = ft_strsub("{green}", 0, 7);
	list->yellow = ft_strsub("{yellow}", 0, 8);
	list->blue = ft_strsub("{blue}", 0, 6);
	list->magenta = ft_strsub("{magenta}", 0, 9);
	list->cyan = ft_strsub("{cyan}", 0, 6);
	list->white = ft_strsub("{white}", 0, 7);
	list->eoc = ft_strsub("{eoc}", 0, 5);
	if (!list->black || !list->red || !list->green || !list->yellow ||
		!list->blue || !list->magenta || !list->cyan || !list->white)
		return (NULL);
}

int		ft_is_it_color(char *str, t_color *list)
{
}

char	*ft_add_colors_to_text(char *str, int len)
{
	int			i;
	int			ret;
	t_color		*list;

	i = 0;
	list = ft_create_color_list(list);
	while (i < ret)
	{
		if (str[i] == '{')
			i = ft_is_it_color(&str[i], list);
		i++;
	}
}

int		ft_colorprintf(const char *c, ...)
{
	t_info		*info;
	va_list		ap;
	char		*str;

	info = NULL;
	if (!(info = ft_create_info(info, 0)))
		return (-1);
	va_start(ap, c);
	str = ft_printf_cycle(c, info, ap);
	if (!str)
		return (0);
	str = ft_add_colors_to_text(str, info->position);
	write(1, str, info->position);
	ft_strdel(&str);
	va_end(ap);
	free(info);
	return (info->position);
}

