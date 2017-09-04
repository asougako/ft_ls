/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:05:08 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 16:42:06 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *dst, const char *src)
{
	size_t	size;

	size = ft_strlen((char *)dst);
	return (ft_strncmp((char *)dst, (char *)src, size + 1));
}
