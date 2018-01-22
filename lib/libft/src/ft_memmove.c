/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:36:19 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 14:48:31 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (dst < src)
	{
		while (tmp_dst < (char *)dst + len)
			*(tmp_dst++) = *(tmp_src++);
	}
	else if (dst > src)
	{
		tmp_dst += len - 1;
		tmp_src += len - 1;
		while ((void *)tmp_dst >= dst)
			*(tmp_dst--) = *(tmp_src--);
	}
	return (dst);
}
