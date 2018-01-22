
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

	if(opt_l)
	{
		print_file_lst_long(file_lst);
	}
	else
	{
		if (opt_x)
			print_file_lst_short_across(file_lst);
		else if (opt_m)
			print_file_lst_short_across_comma(file_lst);
		else if (opt_1)
			print_one_per_line(file_lst);
		else
			print_file_lst_short(file_lst);
	}
}

size_t		ft_strlen_color(const char *str)
{
	size_t	size;
	char	*tmp;

	size = 0;
	tmp = (char*)str;
	while (*tmp)
	{
		if (*tmp == 0x1b)
		{
			tmp = ft_strchr(tmp, 'm');
		}
		else
		{
			size++;
		}
		tmp++;
	}
	return(size);
}

#define FILE_NAME (*(t_xstat*)(*file_lst).content).str_name
int	get_name_max_size(t_list *file_lst)
{
	int	maxsize;
	int	tmp;

	maxsize = 0;
	while (file_lst != NULL)
	{
		tmp = ft_strlen_color(FILE_NAME);
		if (tmp > maxsize)
		{
			maxsize = tmp;
		}
		file_lst = (*file_lst).next;
	}
	maxsize++;
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

void	padding(char **buff, char *src, int colw)
{
	char *tmp;
	int size_nc;
	int	size_wc;

	tmp = *buff;
	while (*tmp != '\0')
		tmp++;
	ft_strcpy(tmp, src);
	size_nc = ft_strlen_color(src);
	size_wc = ft_strlen(src);
	ft_memset(tmp + size_wc, 0x20, colw - size_nc);

}

void	padding_endl(char **buff, char *src)
{
	char *tmp;

	tmp = *buff;
	while (*tmp != '\0')
		tmp++;
	ft_strcpy(tmp, src);
}

void	print_one_per_line(t_list *file_lst)
{
	while(file_lst != NULL)
	{
		ft_putendl((*(t_xstat*)(*file_lst).content).str_name);
		file_lst = (*file_lst).next;
	}
}

#define NAME  (**(tab + (col * line_nb) + line)).str_name
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

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	colw = get_name_max_size(file_lst);
	if (w.ws_col < colw)
		w.ws_col = colw;
	buff = NULL;
	buff = ft_strnew(((w.ws_col / colw) + 1) * (colw + 20));
	col_nb = w.ws_col / colw;
	tab = lst_to_tab(file_lst);
	while(*(tab + list_size) != NULL)
		list_size++;
	line_nb = ((list_size - 1) / col_nb) + 1;
	line = 0;
	while (line < line_nb)
	{
		col = 0;
		ft_bzero(buff, ((w.ws_col / colw) + 1) * (colw + 20));
		while (col < col_nb)
		{
			if (((col * line_nb) + line) < list_size)
			{
				if (col == col_nb - 1)
					padding_endl(&buff, NAME);
				else
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

#define NAME (*(t_xstat*)(*file_lst).content).str_name
void    print_file_lst_short_across_comma(t_list *file_lst)
{
	struct winsize	w;
	int				colw;
	char			*buff;
	int				lnc;
	int				lwc;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	colw = get_name_max_size(file_lst);
	buff = ft_strnew(((w.ws_col / colw) + 1) * (colw + 20));
	lnc = 0;
	lwc = 0;
	while (file_lst != NULL)
	{
		if (lnc + ft_strlen_color(NAME) + 2 > w.ws_col)
		{
			ft_putendl(buff);
			ft_bzero(buff, ((w.ws_col / colw) + 1) * (colw + 11));
			lnc = 0;
			lwc = 0;
		}
		ft_strcpy(buff + lwc, NAME);
		lnc += ft_strlen_color(NAME) + 2;
		lwc += ft_strlen(NAME);
		if ((*file_lst).next != NULL)
		{
			ft_strcpy(buff + lwc, ", ");
			lwc += 2;
		}
		file_lst = (*file_lst).next;
	}
	ft_putendl(buff);
	ft_strdel(&buff);
}
#undef NAME

size_t		get_buff_size(int win_size, int col_size)
{
	size_t ret;

	ret = (win_size / col_size)	* col_size + 11;
	printf("strnew = %zu\n", ret);
	return(ret);
}

void    print_file_lst_short_across(t_list *file_lst)
{
	struct winsize	w;
	int				colw;
	int				lennc;
	int				lenwc;
	char			*buff;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	colw = get_name_max_size(file_lst);
	buff = ft_strnew((w.ws_col / colw) * (colw + 11));
	buff = ft_memset(buff, 0x20, w.ws_col + 66);
	lennc = 0;
	lenwc = 0;
	while (file_lst != NULL)
	{
		ft_strncpy(buff + (lennc * colw) + lenwc, FILE_NAME, ft_strlen(FILE_NAME));
		if (lennc >= (w.ws_col / colw) - 1 || (*file_lst).next == NULL)
		{
			*(buff + (lennc * colw) + lenwc + ft_strlen(FILE_NAME)) = '\0';
			ft_putendl(buff);
			buff = ft_memset(buff, 0x20, (w.ws_col / colw) * (colw + 11));
			lennc = 0;
			lenwc = 0;
		}
		else
		{
			lennc++;
			lenwc += (ft_strlen(FILE_NAME) - ft_strlen_color(FILE_NAME));
		}
		file_lst = (*file_lst).next;
	}
	ft_strdel(&buff);
}

#undef FILE_STAT
#undef FILE_PATH
#undef FILE_NAME
#undef FILE_XATTR
#undef FILE_ERROR
