/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:03 by asougako          #+#    #+#             */
/*   Updated: 2016/11/07 15:09:25 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	index;
	char	*ptr;

	if (!(ptr = (char *)malloc(size * sizeof(*ptr))))
		return (NULL);
	index = 0;
	while (index < size)
		*(ptr + index++) = '\0';
	return ((void *)ptr);
}
