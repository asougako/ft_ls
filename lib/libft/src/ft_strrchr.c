/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:13:22 by asougako          #+#    #+#             */
/*   Updated: 2016/11/18 16:30:42 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	comp;
	char	*src_tmp;

	comp = (char)c;
	src_tmp = (char *)src + ft_strlen((char *)src);
	while (*src_tmp != comp)
		if (src_tmp-- == src)
			return (0);
	return (src_tmp);
}
