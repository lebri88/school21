/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2020/01/06 19:46:52 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>
#include <math.h>
#include <stdio.h>

int     main(void)
{
	int     i;
	
	i = 20;
//	i = ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'Ã ', "Ly", 2, 10, 100, 'q');
//	i = ft_printf("%jjjc", 'q');
//	i = printf("%hhhlll.10 -llib", 125);
	i = ft_printf("%+20j", 12500);
    return (0);
}
 
