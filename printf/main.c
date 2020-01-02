/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2020/01/02 20:39:57 by geliz            ###   ########.fr       */
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
    char  *c;
    char  o;
    char  a;

    o = '1';
    a = '2';
    c = &a;
   // c = ft_strnew(1000000);
    z = 573.924;

    i = ft_printf("1123123123%f", 7.5);
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
 