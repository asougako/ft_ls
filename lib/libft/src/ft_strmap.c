/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:54:45 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 15:24:17 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	tmp = dst;
	while (*s)
		*(tmp++) = (*f)(*s++);
	return (dst);
}
