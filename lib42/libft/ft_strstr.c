/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:20:57 by asougako          #+#    #+#             */
/*   Updated: 2017/01/25 17:04:24 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *nee)
{
	char	*hay_stop;
	int		i;

	hay_stop = (char *)hay + ft_strlen((char *)hay) - ft_strlen((char *)nee);
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
