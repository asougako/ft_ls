/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:18:37 by asougako          #+#    #+#             */
/*   Updated: 2016/11/07 13:43:53 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*dst_tmp;

	dst_tmp = (char *)dst;
	while (dst_tmp < (char *)dst + len)
		*dst_tmp++ = *(char *)src++;
	return (dst);
}
