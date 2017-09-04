/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_intlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:54:56 by asougako          #+#    #+#             */
/*   Updated: 2017/01/06 16:51:10 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(uint64_t u_i, size_t base)
{
	size_t		count;

	count = 0;
	if (u_i == 0)
	{
		return (1);
	}
	while (u_i > 0)
	{
		u_i /= base;
		count++;
	}
	return (count);
}
