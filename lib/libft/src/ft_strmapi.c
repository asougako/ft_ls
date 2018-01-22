/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:42:19 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 15:24:51 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	char	*tmp;
	size_t	index;

	if (!s | !f)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	tmp = dst;
	index = 0;
	while (*s)
		*tmp++ = (*f)(index++, *s++);
	return (dst);
}
