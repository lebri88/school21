/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2019/12/03 19:41:12 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int     main(void)
{
    int     i;
///*
    i = ft_printf("% 05i", 43);
    write(1, "\n", 1);
    printf("%.0li", 22337203685477);
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
 