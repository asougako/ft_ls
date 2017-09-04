/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:41:17 by asougako          #+#    #+#             */
/*   Updated: 2016/11/15 11:21:11 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strtab_len(char **src)
{
	int		index;

	index = 0;
	while (*(src + index) != NULL)
	{
		index++;
	}
	return (index);
}
