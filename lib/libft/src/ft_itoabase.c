/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:46:57 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 18:47:03 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoabase(uint64_t u_n, const char *base)
{
	char			*dst;
	unsigned int	index;
	unsigned int	base_size;

	base_size = ft_strlen((char *)base);
	index = ft_intlen(u_n, base_size) - 1;
	if (!(dst = ft_strnew(index + 1)))
		return (NULL);
	if (u_n == 0)
		*(dst) = '0';
	while ((u_n) > 0)
	{
		*(dst + index--) = (*(base + (u_n % base_size)));
		u_n /= base_size;
	}
	return (dst);
}
