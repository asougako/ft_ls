/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_human_readable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:17:33 by asougako          #+#    #+#             */
/*   Updated: 2017/09/04 16:32:16 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_human_readable.h"

char		*ft_human_readable(char *value)
{
	char	*ret;
	int		ret_index;
	int		val_index;
	int		val_len;

	ret = ft_strnew(5);
	ret_index = 0;
	val_index = 0;
	val_len = ft_strlen(value);
	while (ret_index < 3 && val_index < val_len)
	{
		*(ret + ret_index++) = *(value + val_index++);
		if (val_len == 1)
			break ;
		if (ret_index == 1 && (val_len % 3) == 1)
			*(ret + ret_index++) = DEC_SEP;
		if (ret_index == 2 && (val_len % 3) == 2)
			break ;
	}
	return (add_unit(ret, ret_index, val_len));
}

static char	*add_unit(char *ret, int ret_index, int val_len)
{
	if (val_len <= 3)
		*(ret + ret_index) = UNIT;
	else if (val_len <= 6)
		*(ret + ret_index) = KILO;
	else if (val_len <= 9)
		*(ret + ret_index) = MEGA;
	else if (val_len <= 12)
		*(ret + ret_index) = GIGA;
	else if (val_len <= 15)
		*(ret + ret_index) = TERA;
	return (ret);
}
