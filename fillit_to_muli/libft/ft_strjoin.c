/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:19:35 by geliz             #+#    #+#             */
/*   Updated: 2019/10/18 20:33:44 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*str;
	size_t	i;

	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	str = ft_strnew(lens1 + lens2);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s1, lens1);
	i = 0;
	while (s2[i] != '\0')
	{
		str[lens1 + i] = s2[i];
		i++;
	}
	str[lens1 + i] = '\0';
	return (str);
}
