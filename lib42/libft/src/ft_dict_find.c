/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:03:36 by asougako          #+#    #+#             */
/*   Updated: 2017/01/30 14:56:13 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

static int		word_chr(void *content, size_t size, void *word)
{
	if ((ft_strequ((*(t_dictionary*)content).word, word)) != 0)
		return (1);
	(void)size;
	return (0);
}

t_definition	*ft_dict_wchr(t_list *dict, char *name)
{
	t_dictionary *link;

	link = (t_dictionary *)ft_lstchr(&dict, name, &word_chr);
	if  (link == NULL)
		return (NULL);
	else
		return (&(*link).definition);
}

t_definition	*ft_dict_ichr(t_list *dict, int ref)
{
	int index;

	index = 0;
	while (dict != NULL)
	{
		if (index == ref)
		{
			return (&(*(t_dictionary*)(*dict).content).definition);
		}
		dict = (*dict).next;
		index++;
	}
	return (NULL);
}
