/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:06:55 by asougako          #+#    #+#             */
/*   Updated: 2017/01/11 02:59:59 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dst_tmp;
	char	*src_tmp;

	dst_tmp = (char *)dst;
	src_tmp = (char *)src;
	while (dst_tmp < dst + len && *src_tmp)
		*dst_tmp++ = *src_tmp++;
	while (dst_tmp < dst + len)
		*dst_tmp++ = '\0';
	return (dst);
}
