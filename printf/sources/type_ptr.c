/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:51:29 by geliz             #+#    #+#             */
/*   Updated: 2019/12/04 17:31:29 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_info_to_ptr(t_info *in, va_list ap)
{
	if (in->base == 'd')
		return (NULL);
	if (!(ap))
		return (NULL);
	return (NULL);
}