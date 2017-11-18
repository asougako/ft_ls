
#include "ft_ls.h"

#define CONTENT		(t_file_infos*)(*link).content
#define FILE_NAME	(*CONTENT).name
#define FILE_PRINT	(*CONTENT).printable
#define HAS_XATTR	(*CONTENT).has_xattr
#define FILE_TYPE	(*(*CONTENT).stat).st_mode
#define FILE_BLOCKS	(*(*CONTENT).stat).st_blocks

#define FILE_INODE	(*CONTENT).str_inode
#define FILE_MODE	(*CONTENT).str_mode
#define FILE_LINK	(*CONTENT).str_link
#define FILE_USER	(*CONTENT).str_user
#define FILE_GROUP	(*CONTENT).str_group
#define FILE_MAJOR	(*CONTENT).str_major
#define FILE_MINOR	(*CONTENT).str_minor
#define FILE_SIZE	(*CONTENT).str_size
#define FILE_DATE	(*CONTENT).str_date

#define FILE_LIST (t_list*)(*dirlst).content
#define DIRECTORY (*(t_file_infos*)(*FILE_LIST).content).path

#define ERROR_ACCESS (*(t_file_infos*)(*(t_list*)(*dirlst).content).content).error_access
#define ERROR_ACC_STR (*(t_file_infos*)(*(t_list*)(*dirlst).content).content).name
void    print_dir(t_list *dirlst, size_t index)
{
    void	(*print_func)(t_list*);
    int		index2;

    index = 0;
    if (OPT(l))
	print_func = &print_dir_long;
    else
	print_func = &print_dir_short;
    while (dirlst!= NULL)
    {
	if (index2 > 0)
	{
	    ft_putstr(DIRECTORY);
	    ft_putendl(":");
	}
	if (ERROR_ACCESS)
	{
	    ft_putendl(ERROR_ACC_STR);
	}
	else
	{
	    process_opt(FILE_LIST);
	    print_func(FILE_LIST);
	}
	dirlst = (*dirlst).next;
	if (dirlst != NULL)
	    ft_putendl("");
	    index2++;
    }
}
#undef FILE_LIST
#undef DIRECTORY

void	print_col(char *field, uint16_t width)
{
    uint16_t		index;

    if (ft_isdigit(*field))
    {
	index = ft_strlen(field);
	while (index < width)
	{
	    ft_putchar(0x20);
	    index++;
	}
	ft_putstr(field);
    }
    else
    {
	ft_putstr(field);
	index = ft_strlen(field);
	while (index < (width))
	{
	    ft_putchar(0x20);
	    index++;
	}
    }
    ft_putchar(0x20);
}

char	*get_block_total(t_list *link)
{
    char		*ret;
    uint64_t	total;

    total = 0;
    while (link != NULL)
    {
	if ((*CONTENT).printable)
	    total += (*(*CONTENT).stat).st_blocks;
	link = (*link).next;
    }
    ret = ft_itoa(total);
    return(ret);
}


#define  INODE_WIDTH (*colw).inode_w
#define  MODE_WIDTH (*colw).mode_w
#define  LINK_WIDTH (*colw).link_w
#define  USER_WIDTH (*colw).user_w
#define  GROUP_WIDTH (*colw).group_w
#define  MAJOR_WIDTH (*colw).major_w
#define  MINOR_WIDTH (*colw).minor_w
#define  SIZE_WIDTH (*colw).size_w
#define  DATE_WIDTH (*colw).date_w
void	print_dir_long(t_list *file_lst)
{
    t_list		*link;
    t_max_col_width	*colw;

    colw = (t_max_col_width*)ft_memalloc(sizeof(*colw));
    get_long_infos(file_lst, colw);
    link = file_lst;
    if ((*CONTENT).path != NULL)
    {
    	ft_putstr("total ");
    	printf("%s\n", get_block_total(file_lst));
    }
    while(link != NULL)
    {
	if (FILE_PRINT == true)
	{
	    if (OPT(i))
	    {
	    	print_col(FILE_INODE, INODE_WIDTH);
	    }
	    print_col(FILE_MODE, 11);
	    print_col(FILE_LINK, LINK_WIDTH);
	    if (!(OPT(g)))
	    {
	    	print_col(FILE_USER, USER_WIDTH);
    	    	ft_putchar(0x20);
    	    }
	    if (!(OPT(o)))
	    {
	    	print_col(FILE_GROUP, GROUP_WIDTH + 1);
    	    }



	    if (S_ISCHR(FILE_TYPE) || S_ISBLK(FILE_TYPE))
	    {
		print_col(FILE_MAJOR, 4);
		print_col(FILE_MINOR, 3);
	    }
	    else
	    {
		print_col(FILE_SIZE, SIZE_WIDTH);
	    }



	    print_col(FILE_DATE, DATE_WIDTH);
	    ft_putendl(FILE_NAME);
	}
	link = (*link).next;
    }
    ft_memdel((void**)&colw);
}

void	get_long_infos(t_list *head, t_max_col_width *colw)
{
    t_list 		*link;
    uint16_t	tmp;
    uint16_t	tmp2;

    link = head;
    while(link != NULL)
    {
	if ((*CONTENT).printable == true)
	{
	    (*CONTENT).str_inode = get_inode(link);
	    if ((tmp = ft_strlen((*CONTENT).str_inode)) > INODE_WIDTH)
		INODE_WIDTH = tmp;

	    (*CONTENT).str_mode = get_rights(link);
	    // if ((tmp = ft_strlen((*CONTENT).str_mode)) > MODE_WIDTH)
	    //	MODE_WIDTH = tmp;

	    (*CONTENT).str_link = get_links(link);
	    if ((tmp = ft_strlen((*CONTENT).str_link)) > LINK_WIDTH)
		LINK_WIDTH = tmp;

	    (*CONTENT).str_user = get_user(link);
	    if ((tmp = ft_strlen((*CONTENT).str_user)) > USER_WIDTH)
		USER_WIDTH = tmp;

	    (*CONTENT).str_group = get_group(link);
	    if ((tmp = ft_strlen((*CONTENT).str_group)) > GROUP_WIDTH)
		GROUP_WIDTH = tmp;

	    if (S_ISCHR(FILE_TYPE) || S_ISBLK(FILE_TYPE))
	    {
		(*CONTENT).str_major = get_major(link);
//		if ((tmp = ft_strlen((*CONTENT).str_major)) > MAJOR_WIDTH)
//		    MAJOR_WIDTH = tmp;
		(*CONTENT).str_minor = get_minor(link);
//		if ((tmp2 = ft_strlen((*CONTENT).str_minor)) > MINOR_WIDTH)
//		    MINOR_WIDTH = tmp2;
		if ((tmp + tmp2 ) > SIZE_WIDTH)
		    SIZE_WIDTH = 8;
	    }
	    else
	    {
		(*CONTENT).str_size = get_size(link);
		if ((tmp = ft_strlen((*CONTENT).str_size)) > SIZE_WIDTH)
		    SIZE_WIDTH = tmp;
		if (tmp > (MAJOR_WIDTH + MINOR_WIDTH))
		    MAJOR_WIDTH = (tmp - MINOR_WIDTH) - 1;
	    }

	    (*CONTENT).str_date = get_date(link);
	    if ((tmp = ft_strlen((*CONTENT).str_date)) > DATE_WIDTH)
		DATE_WIDTH = tmp;
	}
	link = (*link).next;
    }
}
#undef  MODE_WIDTH
#undef  LINK_WIDTH
#undef  USER_WIDTH
#undef  GROUP_WIDTH
#undef  MAJOR_WIDTH
#undef  MINOR_WIDTH
#undef  SIZE_WIDTH
#undef  DATE_WIDTH

char	*get_rights(t_list *link)
{
    char *ret;

    ret = ft_strnew(11);
    S_ISDIR(FILE_TYPE)  ? *(ret + 0) = 'd' : 0;
    S_ISREG(FILE_TYPE)  ? *(ret + 0) = '-' : 0;
    S_ISLNK(FILE_TYPE)  ? *(ret + 0) = 'l' : 0;
    S_ISCHR(FILE_TYPE)  ? *(ret + 0) = 'c' : 0;
    S_ISBLK(FILE_TYPE)  ? *(ret + 0) = 'b' : 0;
    S_ISFIFO(FILE_TYPE) ? *(ret + 0) = 'p' : 0;
    *(ret + 1) = FILE_TYPE & S_IRUSR ? 'r' : '-';
    *(ret + 2) = FILE_TYPE & S_IWUSR ? 'w' : '-';
    *(ret + 3) = FILE_TYPE & S_IXUSR ? 'x' : '-';
    *(ret + 4) = FILE_TYPE & S_IRGRP ? 'r' : '-';
    *(ret + 5) = FILE_TYPE & S_IWGRP ? 'w' : '-';
    *(ret + 6) = FILE_TYPE & S_IXGRP ? 'x' : '-';
    *(ret + 7) = FILE_TYPE & S_IROTH ? 'r' : '-';
    *(ret + 8) = FILE_TYPE & S_IWOTH ? 'w' : '-';
    *(ret + 9) = FILE_TYPE & S_IXOTH ? 'x' : '-';
    *(ret + 10) = HAS_XATTR ? '+' : '\0';
    return(ret);
}

char	*get_inode(t_list *link)
{
    return (ft_itoa((*(*CONTENT).stat).st_ino));
}

char	*get_links(t_list *link)
{
    return (ft_itoa((*(*CONTENT).stat).st_nlink));
}

char	*get_user(t_list *link)
{
    char			*ret;
    struct passwd	*passwd;

    ret = NULL;
    passwd = NULL;
    if (OPT(n))
	ret = ft_strdup(ft_itoa((*(*CONTENT).stat).st_uid));
    else
    {
	passwd = getpwuid((*(*CONTENT).stat).st_uid);
	ret = ft_strdup((*passwd).pw_name);
    }
    return(ret);
}

char	*get_group(t_list *link)
{
    char	*ret;
    struct group *group = NULL;

    if (OPT(n))
    {
	ret = ft_strdup(ft_itoa((*(*CONTENT).stat).st_gid));
    }
    else
    {
	group = getgrgid((*(*CONTENT).stat).st_gid);
	ret = ft_strdup((*group).gr_name);
    }
    return(ret);
}

char	*get_major(t_list *link)
{
    char	*ret;
    char	*to_free;

    to_free = ft_itoa(major((*(*CONTENT).stat).st_rdev));
    ret = ft_strjoin(to_free, ",");
    ft_memdel((void **)&to_free);
    return (ret);
}

char	*get_minor(t_list *link)
{
    return (ft_itoa(minor((*(*CONTENT).stat).st_rdev)));
}

char	*get_size(t_list *link)
{
    return (ft_itoa((*(*CONTENT).stat).st_size));
}

char	*get_date(t_list *link)
{
    char	*ret;
    char	*tmp;
    char	*cut;
    time_t	time;

    if (OPT(l) && OPT(u))
	time = (*(*CONTENT).stat).st_atime;
    else if (OPT(l) && OPT(c))
	time = (*(*CONTENT).stat).st_ctime;
    else
	time = (*(*CONTENT).stat).st_mtime;

    tmp = ft_strdup(ctime(&time));
    cut = tmp + 16;
    *cut = '\0';
    ret = ft_strdup(tmp + 4);
    ft_memdel((void**)&tmp);
    return(ret);
}

#undef CONTENT
#undef FILE_NAME
#undef FILE_PRINT
#undef HAS_XATTR
#undef FILE_TYPE
#undef FILE_MODE
#undef FILE_LINK
#undef FILE_USER
#undef FILE_GROUP
#undef FILE_MAJOR
#undef FILE_MINOR
#undef FILE_SIZE
#undef FILE_DATE
