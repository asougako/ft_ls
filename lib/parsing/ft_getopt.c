/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:29:44 by asougako          #+#    #+#             */
/*   Updated: 2017/12/01 19:44:19 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include <stdio.h>

char	*ft_optarg;
int		ft_optind = 1;
int 	ft_optopt;
int		ft_opterr;

static t_bool	is_opt(char *arg)
{
	if (*(arg + 0) == '-')
		return	(true);
	else
		return(false);
}

static int		put_illegal_error(char *av0)
{
	ft_opterr = 1;
	ft_putstr_fd(av0, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd((char)ft_optopt, 2);
	ft_putendl_fd("", 2);
	return('?');
}

static int		put_argument_error(char *av0)
{
	ft_opterr = 1;
	ft_putstr_fd(av0, 2);
	ft_putstr_fd(": option requires an argument -- ", 2);
	ft_putchar_fd((char)ft_optopt, 2);
	ft_putendl_fd("", 2);
	return('?');
}

static char *get_arg(char *av[], size_t char_index)
{
	char	*arg;

	if (*(av + ft_optind + 1) == NULL)
	{
		ft_optind++;
		ft_optind++;
		return(NULL);
	}
	if (*(*(av + ft_optind) + char_index + 1) == '\0')
	{
		ft_optind++;
		arg = *(av + ft_optind);
		ft_optind++;
	}
	else
	{
		arg = (*(av + ft_optind) + char_index + 1);
		ft_optind++;
	}
	return(arg);
}

int		ft_getopt(int ac, char **av, const char *opt_str)
{
	static size_t	char_index = 0;
	int				tmp_ind;
	char			*opt_str_index;

	ft_optarg = NULL;
	if (ft_opterr != 0)
		return(-1);
	while (1)
	{
		tmp_ind = ft_optind;
		if (char_index == 0)
		{
			if (*(av + tmp_ind) == NULL)
				return(-1);
			if (is_opt(*(av + tmp_ind)) == false)
				return(-1);
		}
		char_index++;
		ft_optopt = *(*(av + tmp_ind) + char_index);
		if (char_index == 1)
		{
			if (ft_optopt == '\0')
				return(-1);
			if (ft_optopt == '-')
			{
				ft_optind++;
				if (*(*(av + tmp_ind) + char_index + 1) != '\0')
					return(put_illegal_error(*(av + 0)));
				else
					return(-1);
			}
		}
		if (ft_optopt == '-')
			return(put_illegal_error(*(av + 0)));
		if (ft_optopt == '\0')
		{
			char_index = 0;
			ft_optind++;
			continue;
		}
		if ((opt_str_index = ft_strchr(opt_str, ft_optopt)) == NULL)
			return(put_illegal_error(*(av + 0)));
		else if(*(opt_str_index + 1) == ':')
		{
			ft_optarg = get_arg(av, char_index);
			if (ft_optarg == NULL)
				return(put_argument_error(*av));
			char_index = 0;
			return(ft_optopt);
		}
		if (char_index != 0)
			break;
	}
	return(ft_optopt);
}
