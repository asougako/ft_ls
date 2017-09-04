/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:48:41 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 18:50:10 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstchr(t_list **list, void *match, int (*fnc)(void*, size_t, void*))
{
	t_list	*curr_link;

	curr_link = *list;
	while (curr_link != NULL)
	{
		if (((*fnc)((*curr_link).content,\
						(*curr_link).content_size, match)) != 0)
		{
			return ((*curr_link).content);
		}
		curr_link = (*curr_link).next;
	}
	return (NULL);
}
