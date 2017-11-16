/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:03:56 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 15:29:02 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;

	if (!s)
		return (NULL);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(dst, s + start, len));
}
