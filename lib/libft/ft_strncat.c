/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:36:31 by asougako          #+#    #+#             */
/*   Updated: 2016/11/15 18:59:01 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*src_tmp;
	char	*dst_tmp;

	src_tmp = (char *)src;
	dst_tmp = (char *)dst;
	while (*dst_tmp)
		dst_tmp++;
	while (*src_tmp && src_tmp < src + n)
		*dst_tmp++ = *src_tmp++;
	*dst_tmp = '\0';
	return (dst);
}
