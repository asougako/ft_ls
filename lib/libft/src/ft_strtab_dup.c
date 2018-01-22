/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:42:29 by asougako          #+#    #+#             */
/*   Updated: 2016/11/15 11:08:14 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab_dup(char **src)
{
	size_t	index;
	size_t	size;
	char	**dst;

	size = ft_strtab_len(src);
	if ((dst = (char **)malloc(size * sizeof(*dst))) == NULL)
		return (NULL);
	index = 0;
	while (*(src + index) != NULL)
	{
		*(dst + index) = *(src + index);
		index++;
	}
	*(dst + index) = NULL;
	return (dst);
}
