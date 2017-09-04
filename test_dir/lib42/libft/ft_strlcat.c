/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:03:36 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 14:16:58 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst)
	{
		if (i++ == size)
			return (size + ft_strlen(src));
		dst++;
	}
	while (*src && i < size - 1)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (i + ft_strlen(src));
}
