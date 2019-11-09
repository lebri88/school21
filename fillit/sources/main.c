/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:31:25 by geliz             #+#    #+#             */
/*   Updated: 2019/11/09 17:53:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argn, char **argv)
{
	t_list	*first;
	int		ret;

	if (argn != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	if (!(first = ft_lstnew(NULL, 0)))
		return (0);
	ret = ft_readfile(argv[1], first);
	if (ret != 0)
		ret = ft_fill_map(first);
	ft_clean_list(first);
	if (ret == 0)
		write(1, "error\n", 6);
	return (ret);
}
