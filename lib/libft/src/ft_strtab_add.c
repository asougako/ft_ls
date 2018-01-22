/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:43:13 by asougako          #+#    #+#             */
/*   Updated: 2017/01/17 15:43:46 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab_add(char **src, char *str)
{
	size_t	index;
	size_t	size;
	char	**tmp;

	size = ft_strtab_len(src);
	tmp = src;
	if ((src = (char **)malloc((size + 2) * sizeof(*src))) == NULL)
		return (NULL);
	index = 0;
	while (*(tmp + index) != NULL)
	{
		*(src + index) = *(tmp + index);
		index++;
	}
	*(src + index) = str;
	index++;
	*(src + index) = NULL;
	free(tmp);
	return (src);
}
