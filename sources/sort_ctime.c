/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ctime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:39:29 by asougako          #+#    #+#             */
/*   Updated: 2017/11/28 17:00:42 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define file_stat(INDEX) (*((t_xstat*)content ## INDEX)).stat
#define file_ctime(INDEX) (*(*((t_xstat*)content ## INDEX)).stat).st_ctime
#define file_name(INDEX) (*(*((t_xstat*)content ## INDEX)).dir).d_name

int64_t		ctime_sort(void *content1, void *content2)
{
	if (file_stat(1) != NULL && file_stat(2) != NULL)
	{
		if (file_ctime(1) == file_ctime(2))
		{
			return(name_sort(content1, content2));
		}
		else
		{
			return(file_ctime(2) - file_ctime(1));
		}
	}
	return(0);
}

int64_t		rev_ctime_sort(void *content1, void *content2)
{
	return(-ctime_sort(content1, content2));
}
