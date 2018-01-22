/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:56:05 by asougako          #+#    #+#             */
/*   Updated: 2016/11/18 16:29:56 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *dst, const char *src, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (n > ft_strlen(tmp_dst) + 1)
		n = ft_strlen(tmp_dst) + 1;
	if (n > ft_strlen(tmp_src) + 1)
		n = ft_strlen(tmp_src) + 1;
	while (tmp_dst < dst + n)
	{
		if (*(tmp_dst) != *(tmp_src))
		{
			return ((unsigned char)*(tmp_dst) - (unsigned char)*(tmp_src));
		}
		tmp_dst++;
		tmp_src++;
	}
	return (0);
}
