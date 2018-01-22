/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:41:04 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 14:03:46 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*dst;
	char		*src_tmp;

	src_tmp = (char *)src;
	if ((dst = (char *)malloc((1 + ft_strlen(src_tmp)) * sizeof(*dst))) == NULL)
		return (NULL);
	return (ft_strcpy(dst, src_tmp));
}
