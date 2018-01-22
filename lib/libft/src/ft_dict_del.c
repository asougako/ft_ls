/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_del_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:03:16 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 14:54:02 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Delete all/one entry. Return 0 if succeeded.
*/

#include "./libft.h"

static void	del_content(void *content, size_t size)
{
	ft_memdel(&content);
	(void)size;
}

static int	del_if_name(void *content, size_t size, void *match)
{
	if (ft_strequ((*(t_dictionary*)content).word, match))
	{
		ft_memdel(&content);
		return (1);
	}
	(void)size;
	return (0);
}

int			ft_dict_del(t_list **dict)
{
	ft_lstdel(dict, &del_content);
	if (*dict != NULL)
		return (1);
	return (0);
}

int			ft_dict_wdel(t_list **dict, char *name)
{
	return (ft_lstdelif(dict, name, &del_if_name));
}

int			ft_dict_idel(t_list **dict, unsigned int ref)
{
	unsigned int	index;
	t_list			*curr_link;
	t_list			*prev_link;

	index = 0;
	curr_link = *dict;
	prev_link = NULL;
	while (curr_link != NULL)
	{
		if (index == ref)
		{
			if (prev_link == NULL)
				*dict = (*curr_link).next;
			else
				(*prev_link).next = (*curr_link).next;
			ft_lstdelone(&curr_link, &del_content);
			return (0);
		}
		index++;
		prev_link = curr_link;
		curr_link = (*curr_link).next;
	}
	return (1);
}
