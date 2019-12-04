/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2019/12/04 19:59:46 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int     main(void)
{
    int     i;
///*
    i = ft_printf("%#5.0o", 0);
    write(1, "\n", 1);
    printf("%o", 43);
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
 