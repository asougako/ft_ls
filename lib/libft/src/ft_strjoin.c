/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:16:20 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 15:27:58 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		max_len;

	if (!s1 || !s2)
		return (NULL);
	max_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(dst = ft_strnew(max_len + 1)))
		return (NULL);
	dst = ft_strcpy(dst, (char *)s1);
	dst = ft_strcat(dst, (char *)s2);
	return (dst);
}
