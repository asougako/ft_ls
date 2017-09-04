/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:37 by asougako          #+#    #+#             */
/*   Updated: 2016/11/21 16:13:50 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *alpha)
{
	int		ret;
	int		index;
	int		sign;

	ret = 0;
	index = 0;
	sign = 1;
	while (ft_isspace(*(alpha + index)))
		index++;
	if (*(alpha + index) == '+')
		index++;
	else if (*(alpha + index) == '-')
	{
		sign = -1;
		index++;
	}
	while (ft_isdigit(*(alpha + index)))
	{
		ret = ret * 10 + *(alpha + index++) - '0';
	}
	return (sign * ret);
}
