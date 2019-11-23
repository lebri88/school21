/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2019/11/23 20:01:41 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int     main(void)
{
    int     i;
///*
    i = ft_printf("per %-13.2s, %s, %%%% %s  %c", "0123456789", "123", "013", '\n');
    ft_putstr("\nft_printf = ");
    ft_putnbr(i);
    ft_putchar('\n');
    //*/
  ///*  
    i = printf("per %-13.2s, %s, %%%% %s  %c", "0123456789", "123", "013", '\n');
    ft_putstr("\nprintf = ");
    ft_putnbr(i);
    ft_putchar('\n');
    //*/
    return (0);
}
