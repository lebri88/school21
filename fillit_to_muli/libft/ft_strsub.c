/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:10:33 by geliz             #+#    #+#             */
/*   Updated: 2019/10/18 17:11:21 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] != '\0') && (i < start))
		i++;
	if (i != start)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((s[i] != '\0') && (j < len))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if (j != len)
		return (NULL);
	return (str);
}
