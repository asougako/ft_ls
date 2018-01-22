/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:53:52 by asougako          #+#    #+#             */
/*   Updated: 2016/11/15 18:17:39 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *src1, const void *src2, size_t len)
{
	unsigned char	*src1_tmp;
	unsigned char	*src2_tmp;

	src1_tmp = (unsigned char *)src1;
	src2_tmp = (unsigned char *)src2;
	while (src1_tmp < (unsigned char *)src1 + len)
	{
		if (*src1_tmp != *src2_tmp)
		{
			return (*src1_tmp - *src2_tmp);
		}
		src1_tmp++;
		src2_tmp++;
	}
	return (0);
}
