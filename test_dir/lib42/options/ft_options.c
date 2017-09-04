/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:51:45 by asougako          #+#    #+#             */
/*   Updated: 2017/06/27 05:27:11 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_options.h"

uint64_t		ft_parse_options(char **arg, t_list **opt_lst)
{
	int			index;
	uint64_t	opt;

	opt = 0ull;
	while (*++arg != NULL)
	{
		if (*(*(arg + 0)) + 0 == '-' && *(*(arg + 0) + 1) != '-')
		{
			index = 1;
			while (*(*arg + index))
			{
				if (ft_islower(*(*arg + index)))
					*((uint32_t*)&opt + 0) |= 1u << (*(*arg + index) - 'a');
				if (ft_isupper(*(*arg + index)))
					*((uint32_t*)&opt + 1) |= 1u << (*(*arg + index) - 'A');
				index++;
			}
			*arg = NULL;
		}
		else if (*(*arg + 0) == '-' && *(*arg + 1) == '-')
		{
			ft_parse_long_options(arg, opt_lst);
		}
	}
	return (opt);
}

void		ft_parse_long_options(char **arg, t_list **opt_lst)
{
	char		*equal;
	t_option	*cont;
	t_list		*link;

	cont = (t_option*)malloc(sizeof(*cont));
	equal = ft_strchr(*arg + 2, '=');
	if (equal != NULL)
	{
		(*cont).name = ft_strndup((*arg) + 2, equal - ((*arg) + 2));
		(*cont).value = ft_strdup(equal + 1);
	}
	else
	{
		(*cont).name = ft_strdup((*arg) + 2);
		(*cont).value = NULL;
	}
	link = (t_list*)ft_lstnew(cont, sizeof(*cont));
	ft_lstadd_tail(opt_lst, link);
	*arg = NULL;
}

void			ft_print_short_options(uint64_t params)
{
	int		index;
	char	tmp_char;

	index = 0;
	while (params != 0)
	{
		if ((params & 1ull) == 1)
		{
			if (index < 32)
				tmp_char = 'a' + index;
			else
				tmp_char = 'A' + (index - 32);
			write(1, &tmp_char, 1);
		}
		params >>= 1;
		index++;
	}
}

void			ft_print_long_options(t_list *opt_lst)
{
	while (opt_lst != NULL)
	{
		ft_putstr((*(t_option*)(*opt_lst).content).name);
		if ((*(t_option*)(*opt_lst).content).value != NULL)
		{
			ft_putstr(" = ");
			ft_putendl((*(t_option*)(*opt_lst).content).value);
		}
		opt_lst = (*opt_lst).next;
	}
}
