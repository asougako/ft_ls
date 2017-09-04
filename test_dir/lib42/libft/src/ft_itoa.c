/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:00 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 18:46:16 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint64_t		twos_coplement(int64_t n)
{
	uint64_t	u_n;

	u_n = (uint64_t)~n;
	u_n++;
	return (u_n);
}

char				*ft_itoa(int64_t n)
{
	uint64_t	u_n;
	char		*dst;

	dst = ft_strnew(0);
	u_n = (uint64_t)n;
	if ((n >> (sizeof(n) * 8 - 1)) & 1)
	{
		u_n = twos_coplement(n);
		dst = ft_strjoin(dst, "-");
	}
	dst = ft_strjoin(dst, ft_itoabase(u_n, "0123456789"));
	return (dst);
}
