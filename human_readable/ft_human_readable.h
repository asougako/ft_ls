/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_human_readable.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:18:35 by asougako          #+#    #+#             */
/*   Updated: 2017/09/04 16:32:44 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HUMAN_READABLE_H
# define FT_HUMAN_READABLE_H

# include "libft.h"

# define DEC_SEP '.'
# define UNIT 'B'
# define KILO 'K'
# define MEGA 'M'
# define GIGA 'G'
# define TERA 'T'

char		*ft_human_readable(char *value);
static char	*add_unit(char *str, int ret_index, int val_len);

#endif
