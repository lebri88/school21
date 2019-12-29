/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2019/12/29 19:22:14 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <float.h>
#include <math.h>

int     main(void)
{
    int     i;
    long double  z;
    
    z = 573.924;

    i = ft_printf("%Lf", z);
  //  printf("\n%Lf", z);
  /*  printf("\n%2f", INFINITY);
    printf("\n%5f", INFINITY);
    printf("\n% f", INFINITY);
    printf("\n%+.10f", INFINITY);*/
//    ft_putstr("\nft_printf = ");
 //  ft_putnbr(i);
//    ft_putchar('\n');
    
  /*  
    i = printf("%с", 0);
    ft_putstr("\nprintf = ");
    ft_putnbr(i);
    ft_putchar('\n');
    */
    return (0);
}
 