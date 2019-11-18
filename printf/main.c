/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:35:07 by geliz             #+#    #+#             */
/*   Updated: 2019/11/17 17:31:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int     main(void)
{
    int     i;
///*
    i = ft_printf("%09s", "123");
    ft_putstr("\nft_printf = ");
    ft_putnbr(i);
    ft_putchar('\n');
    //*/
    printf("hello, %s.", "123");
    ft_putstr("\nprintf = ");
    ft_putnbr(i);
    ft_putchar('\n');
    return (0);
}
