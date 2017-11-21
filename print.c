
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
	else
	    print_file_lst_short(file_lst);
    }
}


#define FILE_STAT (*(t_xstat*)(*file_lst).content).stat
#define FILE_PATH (*(t_xstat*)(*file_lst).content).path
#define FILE_NAME (*(t_xstat*)(*file_lst).content).name
#define FILE_XATTR (*(t_xstat*)(*file_lst).content).xattr
#define FILE_ERROR (*(t_xstat*)(*file_lst).content).file_error
int	get_name_max_size(t_list *file_lst)
{
    int	maxsize;
    int	tmp;

    maxsize = 0;
    while (file_lst != NULL)
    {
    	tmp = ft_strlen(FILE_NAME);
	if (tmp > maxsize)
	    maxsize = tmp;
	file_lst = (*file_lst).next;
    }
    return(maxsize + 2);
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
    tab = (t_xstat**)ft_memalloc((index + 1) * sizeof(*tab));
    link = head;
    index = 0;
    while(link != NULL)
    {
        *(tab + index) = (t_xstat*)(*link).content;
        index++;
        link = (*link).next;
    }
    return(tab);
}

void    print_file_lst_short(t_list *file_lst)
{

}

void    print_file_lst_short_across(t_list *file_lst)
{
    struct winsize	w;
    int			colw;
    int			index;
    char		*buff;
    char		padd;

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
}

void    print_file_lst_long(t_list *file_lst)
{
    while (file_lst != NULL)
    {
	ft_putendl(FILE_NAME);
	file_lst = (*file_lst).next;
    }
}
#undef FILE_STAT
#undef FILE_PATH
#undef FILE_NAME
#undef FILE_XATTR
#undef FILE_ERROR
