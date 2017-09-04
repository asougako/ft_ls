/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:06:06 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 14:05:14 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*dst_tmp;

	dst_tmp = (unsigned char *)dst;
	while (dst_tmp < (unsigned char *)dst + len)
	{
		*dst_tmp++ = *(unsigned char *)src++;
		if (*((unsigned char *)src - 1) == (unsigned char)c)
			return (dst_tmp);
	}
	return (NULL);
}
