/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:31:09 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 15:26:15 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_white_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t') ? 1 : 0;
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	char	*tmp;
	int		index;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	while (*tmp && ft_is_white_space(*tmp))
		tmp++;
	index = (int)ft_strlen(tmp) - 1;
	while (index >= 0 && ft_is_white_space(*(tmp + index)))
		index--;
	if (!(dst = ft_strnew(index + 1)))
		return (NULL);
	ft_strncpy(dst, tmp, index + 1);
	return (dst);
}
