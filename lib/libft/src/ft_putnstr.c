/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:21:28 by asougako          #+#    #+#             */
/*   Updated: 2016/12/13 13:45:56 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(const char *str, size_t size)
{
	char	*tmp;

	tmp = NULL;
	tmp = strncpy(tmp, str, size);
	ft_putstr(tmp);
}
