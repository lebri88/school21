/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:31:25 by geliz             #+#    #+#             */
/*   Updated: 2019/11/01 16:13:06 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argn, char **argv)
{
	t_list	*first;
	int		ret;

	if (argn != 2)
	{
		write(1, "arguments error\n", 16);
		return (0);
	}
	ret = ft_readfile(argv[1], first);
	if (ret == 0)
//		ft_cleanlist(first);
	return (ret);
}
