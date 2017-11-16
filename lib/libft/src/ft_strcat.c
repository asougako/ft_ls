/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:28:47 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 14:04:44 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char	*dst_tmp;

	dst_tmp = dst;
	while (*dst_tmp)
		dst_tmp++;
	while ((*(dst_tmp++) = *(src++)))
		;
	return (dst);
}
