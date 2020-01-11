/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2020/01/11 17:04:47 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>


int     main(void)
{
	int     z;

	char	*str;
	str = ft_strsub("poo", 0, 3);
	ft_strdel(&str);
	ft_strdel(&str);
	z = ft_colorprintf("{red}RED{eoc} {white} WHITE!!! {green} gReeN {eoc} default {cyan} CYAN {eoc} {magenta} MAGENTA {black} you can't see this{eoc} {{{{{}}}}} {yellow} like a sun =P {eoc}");
//	i = ft_fprintf(fd, "Here I am! %i and else %c and more %s, and more %f, and all.", 3877, '\0', "moar tests!!!!!", 38.98787);
//	printf("i = %i", i);
//	i = printf("Here I am! %i and else %c and more %s, and more %f, and all.", 3877, '\0', "moar tests!!!!!", 38.98787);
//	printf("i = %i", i);
//	i = ft_printf("%Lf", 3.9999999l);
//	i = ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'Ã ', "Ly", 2, 10, 100, 'q');
//	i = ft_printf("%jjjc", 'q');
//	i = printf("%hhhlll.10 -llib", 125);
//	i = ft_printf("%+20j", 12500);
    return (0);
}
 
