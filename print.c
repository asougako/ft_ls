
#include "ft_ls.h"

void    print_error_lst(t_list *error_lst)
{
	while (error_lst != NULL)
	{
		ft_putendl_fd((char *)(*error_lst).content, 2);
		error_lst = (*error_lst).next;
	}
}

void    print_file_lst(t_list *file_lst)
{
	if(OPT(l))
	{
		print_file_lst_long(file_lst);
	}
	else
	{
		if (OPT(x))
			print_file_lst_short_across(file_lst);
		else if (OPT(m))
			print_file_lst_short_across_comma(file_lst);
		else if (OPT(1))
			print_one_per_line(file_lst);
		else
			print_file_lst_short(file_lst);
	}
}

#define FILE_NAME (*(t_xstat*)(*file_lst).content).name
int	get_name_max_size(t_list *file_lst)
{
	int	maxsize;
	int	tmp;

	maxsize = 0;
	while (file_lst != NULL)
	{
		tmp = ft_strlen(FILE_NAME);
		if (tmp > maxsize)
		{
			maxsize = tmp;
		}
		file_lst = (*file_lst).next;
	}
	maxsize++;
//	while ((maxsize % 8) != 0)
//		maxsize++;
	return(maxsize);
}

t_xstat	**lst_to_tab(t_list *head)
{
	int		index;
	t_list	*link;
	t_xstat	**tab;

	link = head;
	index = 0;
	while(link != NULL)
	{
		index++;
		link = (*link).next;
	}
	if ((tab = (t_xstat**)ft_memalloc((index + 1) * sizeof(*tab))) == NULL)
		print_error_malloc(errno);
	link = head;
	index = 0;
	while(link != NULL)
	{
		if ((*(t_xstat*)(*link).content).stat != NULL)
		{
			*(tab + index) = (t_xstat*)(*link).content;
			index++;
		}
		link = (*link).next;
	}
	return(tab);
}

#define CHAR_PER_TAB 8
void	padding(char **buff, char *src, int colw)
{
	char *tmp;
	int size;

	tmp = *buff;
	while (*tmp != '\0')
		tmp++;

	ft_strcpy(tmp, src);

	size = ft_strlen(src);
	ft_memset(tmp + size, 0x20, colw - size);

}

void	print_one_per_line(t_list *file_lst)
{
	while(file_lst != NULL)
	{
		ft_putendl((*(t_xstat*)(*file_lst).content).name);
		file_lst = (*file_lst).next;
	}
}

#define NAME  (**(tab + (col * line_nb) + line)).name
void    print_file_lst_short(t_list *file_lst)
{
	t_xstat	**tab;
	struct	winsize	w;
	char	*buff;
	int		colw;
	int		list_size = 0;
	int		col = 0;
	int		line = 0;
	int		line_nb = 0;
	int		col_nb = 0;

	//get term width
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	colw = get_name_max_size(file_lst);
	if (w.ws_col < colw)
	{
		w.ws_col = colw;
	}

	buff = NULL;
	buff = ft_strnew(w.ws_col);

	//col nb
	col_nb = w.ws_col / colw;

	//list_size
	tab = lst_to_tab(file_lst);
	while(*(tab + list_size) != NULL)
	{
		list_size++;
	}

	//line nb
	line_nb = ((list_size - 1) / col_nb) + 1;

	//print
	line = 0;
	while (line < line_nb)
	{
		col = 0;
		ft_bzero(buff, w.ws_col);
		while (col < col_nb)
		{
			if (((col * line_nb) + line) < list_size)
			{
				padding(&buff, NAME, colw);
			}
			col++;
		}
		ft_putendl(buff);
		line++;
	}
	ft_strdel(&buff);
	ft_memdel((void**)&tab);
}
#undef NAME

#define NAME (*(t_xstat*)(*file_lst).content).name
void    print_file_lst_short_across_comma(t_list *file_lst)
{
	struct winsize	w;
	char *buff;
	int index;

	buff = NULL;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	buff = ft_strnew(w.ws_col + 1);

	index = 0;

	while (file_lst != NULL)
	{
		if ((index + ft_strlen(NAME) + 2) >= w.ws_col)
		{
			ft_putendl(buff);
			ft_bzero(buff, w.ws_col + 1);
			index = 0;
		}
		ft_strcpy(buff + index, NAME);
		index += ft_strlen(NAME);
		if ((*file_lst).next != NULL)
		{
			ft_strcpy(buff + index, ", ");
			index += 2;
		}
		file_lst = (*file_lst).next;
	}
	ft_putendl(buff);
	ft_strdel(&buff);
}

void    print_file_lst_short_across(t_list *file_lst)
{
	struct winsize	w;
	int				colw;
	int				index;
	char			*buff;
	char			padd;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	colw = get_name_max_size(file_lst);
	if (w.ws_col < colw)
	{
		w.ws_col = colw;
		padd = '\0';
	}
	else
		padd = ' ';
	buff = ft_strnew(w.ws_col);
	buff = memset(buff, padd, w.ws_col);
	index = 0;
	while (file_lst != NULL)
	{
		ft_strncpy(buff + (index * colw), FILE_NAME, ft_strlen(FILE_NAME));
		if (index >= (w.ws_col / colw) - 1)
		{
			ft_putendl(buff);
			buff = memset(buff, padd, w.ws_col);
			index = 0;
		}
		else
		{
			index++;
		}
		file_lst = (*file_lst).next;
	}
	if (index != 0)
		ft_putendl(buff);
	ft_strdel(&buff);
}

#undef FILE_STAT
#undef FILE_PATH
#undef FILE_NAME
#undef FILE_XATTR
#undef FILE_ERROR
