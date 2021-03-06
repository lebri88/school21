/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:55:27 by geliz             #+#    #+#             */
/*   Updated: 2019/09/14 13:11:20 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	z;
	size_t			i;

	i = 0;
	z = c;
	while (len != 0)
	{
		((char *)b)[i] = z;
		i++;
		len--;
	}
	return (b);
}
