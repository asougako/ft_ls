/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_btime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:47:17 by asougako          #+#    #+#             */
/*   Updated: 2017/11/28 17:00:29 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define BTIME_FILE(INDEX) (*(*((t_xstat*)content ## INDEX)).stat).st_birthtime
int64_t		btime_sort(void *content1, void *content2)
{
	if (BTIME_FILE(1) == BTIME_FILE(2))
	{
		return(name_sort(content1, content2));
	}
	else
	{
		return(BTIME_FILE(2) - BTIME_FILE(1));
	}
}

int64_t		rev_btime_sort(void *content1, void *content2)
{
	return(-mtime_sort(content1, content2));
}
