/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:55:48 by asougako          #+#    #+#             */
/*   Updated: 2017/06/02 12:55:15 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

unsigned char	g_base[16] = "0123456789abcdef";
char			g_buffer[17] = {0, 0, 0, 0, 0, 0, 0, 0,\
	0, 0, 0, 0, 0, 0, 0, 0,\
	'\n'};

static int	apocalypse(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		return (c);
	else
		return ('.');
}

void		ft_print_memory(const void *addr, size_t size)
{
	unsigned char	byte;
	unsigned int	byte_index;

	byte_index = 0;
	while (byte_index < size)
	{
		byte = *((char *)addr + byte_index);
		write(1, g_base + (byte >> 4), 1);
		write(1, g_base + (byte & 0x0f), 1);
		*(g_buffer + (byte_index % 16)) = apocalypse(byte);
		if ((byte_index + 1) % 2 == 0)
			write(1, " ", 1);
		if (((byte_index + 1) % 16) == 0)
			write(1, g_buffer, 17);
		byte_index++;
	}
	byte_index = ((byte_index) % 16);
	if (byte_index == 0)
		return ;
	write(1, "                              ", (16 - byte_index) * 2);
	write(1, "         ", ((16 - byte_index) + 1) / 2);
	write(1, g_buffer, byte_index);
}
