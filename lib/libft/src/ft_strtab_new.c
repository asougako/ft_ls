/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:44:00 by asougako          #+#    #+#             */
/*   Updated: 2016/11/15 11:08:41 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab_new(void)
{
	char	**tab;

	if ((tab = (char **)malloc(1 * sizeof(*tab))) == NULL)
		return (NULL);
	*(tab) = NULL;
	return (tab);
}
