/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2019/12/27 21:57:24 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <float.h>

int     main(void)
{
    int     i;
    double  z;
    z = 573.924;
///*
    i = ft_printf("%.2000f", DBL_MIN);
    printf("\n%6f", z);
    write(1, "\n", 1);
//    ft_putstr("\nft_printf = ");
 //  ft_putnbr(i);
//    ft_putchar('\n');
    //*/
  /*  
    i = printf("%с", 0);
    ft_putstr("\nprintf = ");
    ft_putnbr(i);
    ft_putchar('\n');
    */
    return (0);
}
 