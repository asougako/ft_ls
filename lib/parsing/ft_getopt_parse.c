/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:26:13 by asougako          #+#    #+#             */
/*   Updated: 2017/11/28 11:26:14 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_getopt.h"

#define CURR_ARG *(av + ac)
#define CURR_ARG_CHAR(INDEX) *(CURR_ARG + INDEX)
t_sopt	parse_opt(int ac, char **av)
{
		uint64_t	opt;
		t_list		*lopt;
		t_sopt		sopt;

		opt = 0ull;
		lopt = NULL;
		ac--;
		while (CURR_ARG_CHAR(0) == '-' && CURR_ARG_CHAR(1) != '\0')
		{
				if (CURR_ARG_CHAR(1) != '-')
				{
						parse_short_opt(CURR_ARG, &opt);
				}
				else
				{
						parse_long_opt(&CURR_ARG, &lopt);
				}
				ac--;
		}
		sopt.opt = opt;
		sopt.lopt = lopt;
		return(sopt);
}
#undef CURR_ARG
#undef CURR_ARG_CHAR

void			parse_short_opt(char *arg, uint64_t *opt)
{
		int	index;
		int	shift;

		index = 1;
		while (*(arg + index) != '\0')
		{
				if (ft_isdigit(*(arg + index)))
						shift = (*(arg + index) - '0') + 0;
				if (ft_isupper(*(arg + index)))
						shift = (*(arg + index) - 'A') + 10;
				if (ft_islower(*(arg + index)))
						shift = (*(arg + index) - 'a') + 36;
				if (shift < 32)
						*opt |= 1ull << shift;
				else
						*((uint32_t*)opt + 1) |= 1ull << (shift - 32);
				index++;
		}

}

void			parse_long_opt(char **arg, t_list **lopt)
{
		char        *equal;
		t_loption    *cont;
		t_list      *link;

		cont = (t_loption*)malloc(sizeof(*cont));
		equal = ft_strchr(*arg, '=');


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
		ft_lstadd_tail(lopt, link);
}
