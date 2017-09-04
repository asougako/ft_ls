/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:57:34 by asougako          #+#    #+#             */
/*   Updated: 2017/09/04 15:59:32 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getopt.h"

uint64_t	ft_getopt(int ac, char **av, t_list **lopt)
{
	uint64_t	opt;

	av_sort(av);
	opt = parse_opt(ac, av, lopt);
	clear_opt(ac, av);
	return (opt);
}

#define CURR_ARG *(av + index)
#define PREV_ARG *((av + index) - 1)

static void	av_sort(char **av)
{
	int		index;
	uint8_t	again;

	again = 1;
	while (again == 1)
	{
		index = 1;
		again = 0;
		while (CURR_ARG != NULL)
		{
			if (arg_comp(PREV_ARG, CURR_ARG) > 0)
			{
				PREV_ARG = (char*)((uint64_t)PREV_ARG ^ (uint64_t)CURR_ARG);
				CURR_ARG = (char*)((uint64_t)CURR_ARG ^ (uint64_t)PREV_ARG);
				PREV_ARG = (char*)((uint64_t)PREV_ARG ^ (uint64_t)CURR_ARG);
				again = 1;
			}
			index++;
		}
	}
}

#undef CURR_ARG
#undef PREV_ARG
#define PREV_ARG(INDEX)	*(prev_arg + INDEX)
#define CURR_ARG(INDEX)	*(curr_arg + INDEX)

static int	arg_comp(const char *prev_arg, const char *curr_arg)
{
	if (PREV_ARG(0) != '-')
		return (0);
	if (PREV_ARG(0) == '-' && PREV_ARG(1) == 0x00)
		return (0);
	if (PREV_ARG(0) == '-' && PREV_ARG(1) != 0x00)
	{
		if (CURR_ARG(0) != '-')
			return (1);
		if (CURR_ARG(0) == '-' && CURR_ARG(1) == 0x00)
			return (1);
	}
	return (0);
}

#undef CURR_ARG
#undef PREV_ARG
#define CURR_ARG *(av + ac)

static void	clear_opt(int ac, char **av)
{
	ac--;
	while (*(*(av + ac) + 0) == '-' && *(*(av + ac) + 1) != '\0')
	{
		CURR_ARG = NULL;
		ac--;
	}
}

#undef CURR_ARG
