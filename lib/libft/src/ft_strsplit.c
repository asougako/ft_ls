/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:35:19 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 15:27:11 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		word_len;
	char	*tmp;
	char	**ret;

	if (!s)
		return (NULL);
	ret = ft_strtab_new();
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_len = 0;
			while (*(s + word_len) != c && *(s + word_len))
				word_len++;
			if (!(tmp = ft_strnew(word_len + 1)))
				return (NULL);
			tmp = ft_strncpy(tmp, ((char *)s), word_len);
			ret = ft_strtab_add(ret, tmp);
			s += word_len;
		}
	}
	return (ret);
}
