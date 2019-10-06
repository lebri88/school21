/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:58:32 by geliz             #+#    #+#             */
/*   Updated: 2019/10/06 17:49:14 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);

int		main(int argn, char **argv)
{
	char	*str;
	int		fd;
	int		a;

	if (argn < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((a = get_next_line(fd, &str)) > 0)
	{
		printf("%s\n", str);
		if (a == 0)
			return (0);
	}
	return (0);
}
