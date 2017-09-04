/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 03:04:40 by asougako          #+#    #+#             */
/*   Updated: 2017/01/17 15:43:15 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char		*dst;

	if (!(dst = ft_strnew(size)))
		return (NULL);
	dst = ft_strncpy(dst, (char *)src, size);
	return (dst);
}
