/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:59:42 by geliz             #+#    #+#             */
/*   Updated: 2019/09/22 14:37:53 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	z;
	size_t	i;

	z = ft_strlen(src);
	dest = malloc(sizeof(char) * (z + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i != (z + 1))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
