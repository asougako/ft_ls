/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:55:48 by asougako          #+#    #+#             */
/*   Updated: 2017/06/05 11:05:37 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

unsigned char	g_base[16] = "0123456789abcdef";
char			g_buffer[18] = {' ',\
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
	'\n'};
char			g_addr_buffer[16] = {'0', 'x',\
	'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',\
	' ', ' '};

static int	apocalypse(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		return (c);
	else
		return ('.');
}

void		put_addr(void *addr)
{
	int					index;
	unsigned long long	addr_cpy;

	ft_strcpy(g_addr_buffer, "0x000000000000  ");
	index = 13;
	addr_cpy = (unsigned long long)addr;
	while (addr_cpy > 0)
	{
		*(g_addr_buffer + index) = *(g_base + (addr_cpy % 16));
		addr_cpy /= 16;
		index--;
	}
	write(1, g_addr_buffer, 16);
}

void		ft_print_memory(const void *addr, size_t size)
{
	unsigned char	byte;
	unsigned int	byte_index;

	if (addr == NULL)
	{
			write(1, "(null)\n", 7);
			return;
	}
	byte_index = 0;
	while (byte_index < size)
	{
		if (byte_index % 16 == 0)
			put_addr((char *)addr + byte_index);
		byte = *((char *)addr + byte_index);
		write(1, g_base + (byte >> 4), 1);
		write(1, g_base + (byte & 0x0f), 1);
		*(g_buffer + (byte_index % 16) + 1) = apocalypse(byte);
		if ((byte_index + 1) % 2 == 0)
			write(1, " ", 1);
		if (((byte_index + 1) % 16) == 0)
			write(1, g_buffer, 18);
		byte_index++;
	}
	byte_index = ((byte_index) % 16);
	if (byte_index == 0)
			return;
	write(1, "                              ", (16 - byte_index) * 2);
	write(1, "         ", ((16 - byte_index) + 1) / 2);
	write(1, g_buffer, byte_index + 1);
	write(1, "\n", 1);
}
