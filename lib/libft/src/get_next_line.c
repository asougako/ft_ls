/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asougako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:15:35 by asougako          #+#    #+#             */
/*   Updated: 2016/12/12 11:34:33 by asougako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	Delete the link holding 'fd' without breaking the list.
*/

static int		delete_link(t_list *lst, int fd)
{
	t_list			*tmp;

	while ((*lst).next != NULL)
	{
		if ((*((t_buffer *)((*(*lst).next).content))).fd == fd)
		{
			tmp = (*lst).next;
			(*lst).next = (*(*lst).next).next;
			ft_memdel((void**)&(*(t_buffer *)((*tmp).content)).buff);
			ft_memdel((void**)&(*tmp).content);
			ft_memdel((void**)&tmp);
			return (0);
		}
		lst = (*lst).next;
	}
	return (1);
}

/*
**	Add a new link with the current fd and a fresh buffer.
*/

static t_list	*new_link(t_list *lst, int fd)
{
	t_list			*link;
	t_buffer		*buffer;

	if ((buffer = (t_buffer *)malloc(sizeof(*buffer))) == NULL)
	{
		return (NULL);
	}
	(*buffer).fd = fd;
	(*buffer).buff = NULL;
	if (((*buffer).buff = ft_strnew(BUFF_SIZE + 1)) == NULL)
	{
		return (NULL);
	}
	ft_memset((*buffer).buff, 0, BUFF_SIZE + 1);
	link = ft_lstnew(buffer, sizeof(*buffer));
	ft_lstadd(&lst, link);
	ft_memdel((void**)&buffer);
	return (lst);
}

/*
**	Seak for the buffer associated with 'fd' then return this buffer,
**	if 'fd' is not found, call new_link() and return the newly created
**	buffer.
*/

static char		*get_buffer(t_list **lst, int fd)
{
	t_list			*lst_pointer;

	lst_pointer = *lst;
	while (lst_pointer != NULL)
	{
		if ((*((t_buffer *)((*lst_pointer).content))).fd == fd)
		{
			return ((*((t_buffer *)((*lst_pointer).content))).buff);
		}
		lst_pointer = (*lst_pointer).next;
	}
	*lst = new_link(*lst, fd);
	return ((*((t_buffer *)((**lst).content))).buff);
}

/*
**	Read file and fill 'line'.
*/

static int		get_line(char **line, char *buffer, int fd)
{
	char			*tmp;
	char			*to_be_free;

	tmp = buffer;
	while (*tmp != '\0')
	{
		if (*tmp == '\n')
		{
			*tmp = '\0';
			to_be_free = *line;
			*line = ft_strjoin(*line, buffer);
			ft_memdel((void**)&to_be_free);
			buffer = ft_strcpy(buffer, tmp + 1);
			return (-2);
		}
		tmp++;
	}
	to_be_free = *line;
	*line = ft_strjoin(*line, buffer);
	ft_memdel((void**)&to_be_free);
	ft_memset(buffer, 0, BUFF_SIZE + 1);
	return (read(fd, buffer, BUFF_SIZE));
}

/*
** Main function.
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*buff_list;
	char			*buffer;
	int				ret;

	buffer = NULL;
	if (line == NULL)
		return (-1);
	else
		*line = ft_strnew(0);
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if ((buffer = get_buffer(&buff_list, fd)) == NULL)
		return (-1);
	while ((ret = get_line(line, buffer, fd)) > 0)
		;
	if (ret == -2)
		return (1);
	if (ret == 0 && ft_strlen(*line) != 0)
		return (1);
	if (ret == 0)
		delete_link(buff_list, fd);
	return (ret);
}
