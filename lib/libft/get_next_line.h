/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:10:30 by asougako          #+#    #+#             */
/*   Updated: 2016/12/13 10:48:35 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft.h"
# define BUFF_SIZE 1024

typedef	struct	s_buffer
{
	int				fd;
	unsigned int	size;
	char			*buff;
}					t_buffer;

int				get_next_line(const int fd, char **line);
#endif
