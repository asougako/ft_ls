/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:04:34 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 14:03:35 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char	comp;
	char	*src_tmp;

	comp = (char)c;
	src_tmp = (char *)src;
	while (*src_tmp != comp)
		if (*src_tmp++ == '\0')
			return (NULL);
	return (src_tmp);
}
