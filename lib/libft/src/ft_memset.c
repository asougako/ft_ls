/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:12:02 by asougako          #+#    #+#             */
/*   Updated: 2016/11/07 13:44:10 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int filler, size_t len)
{
	char	*src_tmp;

	src_tmp = src;
	while ((void *)src_tmp < src + len)
		*src_tmp++ = (unsigned char)filler;
	return (src);
}
