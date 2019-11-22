/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:35:15 by geliz             #+#    #+#             */
/*   Updated: 2019/11/22 16:39:13 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_hub(char *buf, t_list *first)
{
	char	**cuted;
	int		ret;

	buf[20] = '\0';
	ret = ft_validate_lines(buf);
	if (ret != 0 && (!(cuted = ft_cutstring(buf))))
		ret = 0;
	if (ret != 0 && (ft_fill_list(cuted, first) == 0))
	{
		ft_clean_list(first);
		ret = 0;
	}
	return (ret);
}

int		ft_readfile(char *file, t_list *first)
{
	int		fd;
	int		res;
	char	buf[20];

	res = 1;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while (res != 0)
	{
		if (res == 1 && ((res = read(fd, buf, 20)) < 20))
			return (0);
		if (ft_hub(buf, first) == 0)
			return (0);
		res = read(fd, buf, 1);
		if (res == 1 && buf[0] != '\n')
			return (0);
	}
	if (ft_fill_content_size(first) == 0)
		return (0);
	return (1);
}
