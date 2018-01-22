/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:48:41 by asougako          #+#    #+#             */
/*   Updated: 2016/11/18 13:21:14 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*src_tmp;
	unsigned char	u_c;

	u_c = (unsigned char)c;
	src_tmp = (unsigned char *)src;
	while (src_tmp < (unsigned char *)src + len)
	{
		if (*(src_tmp) == u_c)
			return ((src_tmp));
		src_tmp++;
	}
	return (NULL);
}
