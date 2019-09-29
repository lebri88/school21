/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:58:32 by geliz             #+#    #+#             */
/*   Updated: 2019/09/29 16:51:11 by geliz            ###   ########.fr       */
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

	if (argn < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str))
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}
