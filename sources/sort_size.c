/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:01:31 by asougako          #+#    #+#             */
/*   Updated: 2017/11/28 17:01:32 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define file_size(INDEX) (*(*((t_xstat*)content ## INDEX)).stat).st_size
#define file_name(INDEX) (*(*((t_xstat*)content ## INDEX)).dir).d_name

int64_t	size_sort(void *content1, void *content2)
{
    if (file_size(1) == file_size(2))
    {
	return(name_sort(content1, content2));
    }
    else
    {
	return(file_size(2) - file_size(1));
    }
}

int64_t	rev_size_sort(void *content1, void *content2)
{
    return(-size_sort(content1, content2));
}
#undef file_size
#undef file_name
