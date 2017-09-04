/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:54:58 by asougako          #+#    #+#             */
/*   Updated: 2017/09/04 15:55:23 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_getopt.h"

void		ft_print_short_options(uint64_t params)
{
	int		index;
	char	tmp_char;

	index = 0;
	while (params != 0)
	{
		if ((params & 1ull) == 1)
		{
			if (index < 10)
				tmp_char = '0' + index;
			else if (index < 36)
				tmp_char = 'A' + (index - 10);
			else
				tmp_char = 'a' + (index - 36);
			write(1, &tmp_char, 1);
		}
		params >>= 1;
		index++;
	}
}

void		ft_print_long_options(t_list *opt_lst)
{
	while (opt_lst != NULL)
	{
		if ((*(t_option*)(*opt_lst).content).value != NULL)
		{
			ft_putstr((*(t_option*)(*opt_lst).content).name);
			ft_putstr(" = ");
			ft_putendl((*(t_option*)(*opt_lst).content).value);
		}
		else
		{
			ft_putendl((*(t_option*)(*opt_lst).content).name);
		}
		opt_lst = (*opt_lst).next;
	}
}
