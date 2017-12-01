/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:30:08 by asougako          #+#    #+#             */
/*   Updated: 2017/11/30 19:37:22 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft/libft.h"

/*
 * Extern
 */
extern char	*ft_optarg;
extern int	ft_optind;
int			ft_optopt;
int			ft_opterr;

/*
 * Functions
 */
int     ft_getopt(int ac, char **av, const char *opt_str);

#endif
