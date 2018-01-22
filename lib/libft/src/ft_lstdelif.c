/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:36:18 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 18:41:11 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstdelif
	(t_list **list, void *match, int (*del)(void*, size_t, void*))
{
	t_list	*curr_link;
	t_list	*prev_link;
	int		del_link_nb;

	curr_link = *list;
	prev_link = NULL;
	del_link_nb = 0;
	while (curr_link != NULL)
	{
		if (((*del)((*curr_link).content,\
						(*curr_link).content_size, match)) != 0)
		{
			if (prev_link == NULL)
				*list = (*curr_link).next;
			else
				(*prev_link).next = (*curr_link).next;
			del_link_nb++;
		}
		prev_link = curr_link;
		curr_link = (*curr_link).next;
	}
	return (del_link_nb);
}
