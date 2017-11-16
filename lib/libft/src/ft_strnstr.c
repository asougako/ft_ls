/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:52:25 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 14:01:13 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t size)
{
	size_t	i;
	char	*hay_stop;

	if ((hay_stop = (char *)hay + ft_strlen((char *)hay)) > (char *)hay + size)
		hay_stop = (char *)hay + size;
	hay_stop -= ft_strlen((char *)nee);
	while (hay <= hay_stop && !(i = 0))
	{
		while (*(nee + i) == *(hay + i) && *(nee + i))
			i++;
		if (!*(nee + i))
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
